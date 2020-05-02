//Sky DeBaun -> CS170 -> Intro to Artificial Intelligence -> Project 01
//Professor Niloofar Montazeri -> Spring 2020
//A* -> eight-puzzle


//includes----------------------------------------------
#include <iostream>
#include "state.h"
#include "problem.h"

using std::cin;


//MAIN---------------------------------------------------
//-------------------------------------------------------
int main()
{
	State myPuzzle; //initialize the default puzzle

	//user prompt for default or custom puzzle----------
	size_t selectPuzzle;

	cout << "Enter 0 for default 8-puzzle, or 1 to enter custom puzzle:" << "\n";
	cin >> selectPuzzle;

	//puzzle initialization-----------------------------
	if (selectPuzzle)
	{
		//enter custom puzzle here:
		myPuzzle.createCustomState();
		cout << "\n" << "Your puzzle: \n";

	}
	else
	{
		cout << "\n" << "The default puzzle: \n";

	}//end if_else--//

	//print current puzzle-----------------------------
	myPuzzle.printState();


	
	return 0;

}//END MAIN----------------------------------------------///




