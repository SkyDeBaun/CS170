//holds tiles states for n-puzzle (defaults to 3x3 = 8-puzzle)
#pragma once

#include<iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::cin;

class State
{
protected:
	vector<int> startState;
	vector<int> defaultState = { 1, 0, 3, 4, 2, 6, 7, 5, 8 }; //default puzzle grid
	size_t gridSize = 3; //size of puzzle grid-> 3x3, 4x4, etc



public:
	//default constructor----------------Default puzzle
	State()
	{
		size_t loopFor = gridSize * gridSize;

		for (size_t i = 0; i < loopFor; ++i)
		{
			startState.push_back(defaultState[i]);//copy default puzzle state
		}

	}//end default constructor---//


	//constructor-------------------------copy puzzle
	State(size_t &_gridSize, vector<int> &vec):gridSize(_gridSize)
	{
		size_t loopFor = gridSize * gridSize;

		for (size_t i = 0; i < loopFor; ++i)
		{
			startState.push_back(vec[i]);//copy user defined puzzle
		}
	}//end stateCopy constructor---//

	//copy constructor---------------------
	State(const State &copy)
	{
		gridSize = copy.gridSize;
		startState = copy.startState;

	}//end copy constructor---//


	size_t getSize()
	{
		return this->gridSize;
	}

	void printState()
	{
		size_t position = 0;

		for (size_t i = 0; i < startState.size(); ++i)
		{			
			cout << startState[i] << " ";
			if ((i+1) % gridSize == 0)
			{
				cout << endl;
			}
		}
	}//end printState---//


	void createCustomState(size_t &_gridSize)
	{
		startState.clear(); //clear the puzzle state
		gridSize = _gridSize;//update object gridsize to maintain print rows via modulo

		size_t newSize = _gridSize * _gridSize;
		cout << "Enter the " << newSize << " tiles" << endl;
		size_t pos;

		for (size_t i = 0; i < newSize; ++i)
		{
			cin >> pos;
			startState.push_back(pos);
		}

	}//end createCustomState---//

	void resizeState(size_t &_gridSize)
	{
		createCustomState(_gridSize);
	}

};

