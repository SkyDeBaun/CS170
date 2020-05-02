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
	vector<int> state;
	vector<int> defaultState = { 1, 0, 3, 4, 2, 6, 7, 5, 8 }; //default puzzle grid
	size_t gridSize = 3; //size of puzzle grid-> 3x3, 4x4, etc



public:
	//default constructor----------------Default puzzle
	State()
	{
		size_t loopFor = gridSize * gridSize;

		for (size_t i = 0; i < loopFor; ++i)
		{
			state.push_back(defaultState[i]);//copy default puzzle state
		}

	}//end default constructor---//


	//constructor-------------------------User generated puzzle
	State(size_t _gridSize, vector<int> &vec):gridSize(_gridSize)
	{
		size_t loopFor = gridSize * gridSize;

		for (size_t i = 0; i < loopFor; ++i)
		{
			state.push_back(vec[i]);//copy user defined puzzle
		}
	}


	size_t getSize()
	{
		return this->gridSize;
	}

	void printState()
	{
		size_t position = 0;

		for (size_t i = 0; i < state.size(); ++i)
		{			
			cout << state[i] << " ";
			if ((i+1) % gridSize == 0)
			{
				cout << endl;
			}
		}
	}//end printState---//


	void createCustomState()
	{
		cout << "Enter positions of the tiles" << endl;
		size_t pos;

		for (int i = 0; i < 9; ++i)
		{
			cin >> pos;
			state[i] = pos;
		}

	}//end createCustomState---//




};

