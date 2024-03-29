//Sky DeBaun -> CS170 -> Intro to Artificial Intelligence -> Project 01
//Professor Niloofar Montazeri -> Spring 2020
//A* -> eight-puzzle (by default, use menu to create other sized puzzles.. use caution!)


//includes----------------------------------------------
#include <iostream>
#include "state.h"
#include "problem.h"
#include "operators.h"
#include "Timer.h"



//MAIN---------------------------------------------------
//-------------------------------------------------------
int main()
{
	//srand(time(NULL));

	//default setup for eight-puzzle--------------------
	vector<int> goal = { 1, 2, 3, 4, 5, 6, 7, 8, 0 }; //goal state for eight-puzzle
	vector<int> defaultState = { 1, 0, 3, 4, 2, 6, 7, 5, 8 }; //default puzzle grid

	//simple case for testing---------------------------maybe
	vector<int> four_goal = { 1, 2, 3, 0 };
	vector<int> four_defaultState = { 1, 0, 3, 2 };

	//create the two puzzle states
	State goalState(goal);
	State myPuzzle(defaultState);

	Operators operators;//map of operators for eight-puzzle(future consideration-> automate on puzzle size)
	Timer t; //init timer object


	//user prompt for default or custom puzzle----------
	size_t selectPuzzle; 

	cout << "Enter 0 for default 8-puzzle, or 1 to enter custom 8-puzzle:" << "\n";
	cin >> selectPuzzle;

	//puzzle initialization-----------------------------
	if (selectPuzzle)
	{	
		selectPuzzle = 3;
		//cout << "Enter  puzzle size (i.e. 3 for 3x3 = 8 puzzle) \n";
		//cin >> selectPuzzle; //re-using user input variable here ->size ie 3 = 3x3 = 9(eight-puzzle)
		myPuzzle.createCustomState(selectPuzzle);

		cout << "\n" << "Your puzzle: \n";
	}
	else //0
	{
		cout << "\n" << "The default puzzle: \n";
	}//end if_else--//

	//print current puzzle-----------------------------
	myPuzzle.printState();

	cout <<"\n"<< "MENU: \n";
	cout << "1.) Uniform Cost Search \n";
	cout << "2.) A* with Misplaced Tile heuristic \n";
	cout << "3.) A* with Euclidian distance heuristic \n\n";
	cout << "-> ";
	int userInput;
	cin >> userInput;

	//solution discovery-------------------------------
	Problem solution(myPuzzle, goalState, operators, userInput);//initialize problem solution
	
	t.startTimer();
	solution.solve();
	t.stopTimer();

	cout << "Time to find solution: "  << std::fixed << t.getSeconds() << " seconds" << endl;


	return 0;

}//END MAIN----------------------------------------------///




