#pragma once

#include <random>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "state.h"
#include <map>

using std::map;
using std::make_pair;

class Distance
{

protected:
	vector<int> myGoal; //cheesy hack...should be avoided -> running into circular dependency issue!!

public:

	Distance()
	{
		vector<int> goal = { 1, 2, 3, 4, 5, 6, 7, 8, 0 }; //duplicating goal state for eight-puzzle->lame!
		myGoal = goal;
	}

	inline void columnComp(int &val)
	{
		if (val == 0)
		{
			val = val + 3;
		}
	}
	inline void rowComp(int &val)
	{
		if (val == 0)
		{
			val = val + 1;
		}
	}
		
	
	inline int getManhattanDistance(const State &state)
	{
		int size = state.returnSize();// state.returnSize(); //get number of elements
		int x;
		int x2;
		int y;
		int yPosition;
		int y2;
		int dx;
		int dy = 0;
		int dist = 0;
		srand(time(NULL));
		//dist = state.returnState(0);//tmp test

		////tmp
		//dist = rand() & 100;

		map<int, int> goalPositions;
		map<int, int> currentPositions;

		//populate maps with index-val pair--------------------
		for (int i = 0; i < size; ++i)
		{
			goalPositions.insert(make_pair(myGoal[i], i));//could be made once instead
			currentPositions.insert(make_pair(i, state.returnState(i)));//same here, for default state
		}

		for (int i = 0; i < size; ++i)
		{
			x = currentPositions.find(i)->second;//get value at index i
			x2 = goalPositions.find(x)->second;//get goal position of the value

			y = (i + 1) / 3;
			rowComp(y);			
			
			int y2 = (x2 + 1) / 3;//row
			rowComp(y2);
			
			int xPosition = (i+1) % 3;//gives columns 0, 1, 2
			columnComp(xPosition);//corrects columns to 1, 2, 3
			
			int x2Position = (x2 + 1) % 3;
			columnComp(x2Position);//compensate for 0 index start

			dx = abs(xPosition - x2Position);
			dy = abs(y - y2);

			dist += (dx + dy);

		}
		//----------------------
		//srand(time(NULL));

		//tmp
		//dist = rand() & 100;

		cout << "Dist: " << dist << " \n";
		return dist;//tmp val
	}
	inline int getHeuristic(const State &state)
	{
		int cost = 0;

		return 0;
	}

};

