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
	vector<int> puzzleState;
	vector<int> defaultState = { 1, 0, 3, 4, 2, 6, 7, 5, 8 }; //default puzzle grid
	size_t gridSize = 3; //size of puzzle grid-> 3x3, 4x4, etc



public:
	//default constructor----------------Default puzzle
	State()
	{
		size_t loopFor = gridSize * gridSize;

		for (size_t i = 0; i < loopFor; ++i)
		{
			puzzleState.push_back(defaultState[i]);//copy default puzzle state
		}

	}//end default constructor---//


	//constructor-------------------------copy puzzle
	State(size_t &_gridSize, vector<int> &vec):gridSize(_gridSize)
	{
		size_t loopFor = gridSize * gridSize;

		for (size_t i = 0; i < loopFor; ++i)
		{
			puzzleState.push_back(vec[i]);//copy user defined puzzle
		}
	}//end stateCopy constructor---//

	//copy constructor---------------------
	State(const State &copy)
	{
		gridSize = copy.gridSize;
		puzzleState = copy.puzzleState;

	}//end copy constructor---//


	//print state of puzzle-------------------------------
	void printState()
	{
		size_t position = 0;

		for (size_t i = 0; i < puzzleState.size(); ++i)
		{			
			cout << puzzleState[i] << " ";
			if ((i+1) % gridSize == 0)
			{
				cout << endl;
			}
		}
	}//end printState---//

	//create new puzzle state (also used to resize puzzle from menu)
	void createCustomState(size_t &_gridSize)
	{
		puzzleState.clear(); //clear the puzzle state
		gridSize = _gridSize;//update object gridsize to maintain print rows via modulo

		size_t newSize = _gridSize * _gridSize;
		cout << "Enter the " << newSize << " tiles" << endl;
		size_t pos;

		for (size_t i = 0; i < newSize; ++i)
		{
			cin >> pos;
			puzzleState.push_back(pos);
		}

	}//end createCustomState---//

	//find empty tile----------------------------------
	size_t findEmptyTile() const
	{
		for (size_t i = 0; i < gridSize; ++i)
		{
			if (puzzleState[i] == 0)
			{
				return i;
			}
		}

		return puzzleState.size();//returns out of bounds value!

	}//end findEmptyTile---//

	//swap tiles-----------------------------------------
	void swapTiles(size_t empty, size_t tile)
	{
		size_t tmp = puzzleState[tile];
		puzzleState[tile] = puzzleState[empty];
		puzzleState[empty] = tmp;

	}//end swapTiles---//


	int returnState(size_t i) const
	{
		return puzzleState[i];
	}

	int returnSize() const
	{
		return puzzleState.size();
	}
	
};

