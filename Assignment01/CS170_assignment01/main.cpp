//Sky DeBaun -> CS170 -> Intro to Artificial Intelligence -> Project 01
//Professor Niloofar Montazeri -> Spring 2020
//A* -> eight-puzzle (by default, use menu to create other sized puzzles.. use caution!)


//includes----------------------------------------------
#include <iostream>
#include "state.h"
#include "problem.h"



//MAIN---------------------------------------------------
//-------------------------------------------------------
int main()
{
	State myPuzzle; //initialize the default puzzle

	//user prompt for default or custom puzzle----------
	size_t selectPuzzle;

	cout << "Enter 0 for default 8-puzzle, or 1 to enter custom 8-puzzle:" << "\n";
	cin >> selectPuzzle;

	//puzzle initialization-----------------------------
	if (selectPuzzle)
	{
		cout << "Enter  puzzle size (i.e. 3 for 3x3 = 8 puzzle) \n";
		cin >> selectPuzzle; //re-using user input variable here
		myPuzzle.createCustomState(selectPuzzle);

		cout << "\n" << "Your puzzle: \n";
	}	
	else //0
	{
		cout << "\n" << "The default puzzle: \n";
	}//end if_else--//

	//print current puzzle-----------------------------
	myPuzzle.printState();





	
	return 0;

}//END MAIN----------------------------------------------///




