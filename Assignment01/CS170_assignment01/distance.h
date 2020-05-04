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

	inline void rowComp(int &val)
	{
		if (val == 0)
		{
			val = val + 3;
		}
	}
		
	
	inline int getManhattanDistance(const State &state)
	{
		int size = state.returnSize();// state.returnSize(); //get number of elements
		int x;
		int x2;
		int y;
		int y2;
		int dx;
		int dy = 0;
		int dist = 0;
		//srand(time(NULL));
		//dist = state.returnState(0);//tmp test

		////tmp
		//dist = rand() & 100;

		map<int, int> goalPositions;

		//populate map with index-val pair
		for (int i = 0; i < size; ++i)
		{
			//goalPositions.insert(make_pair(i, goal[i]));
		}

		for (int i = 0; i < size; ++i)
		{
			x = (i + 1) % 3;
			rowComp(x);//ie cols 1, 2, 3
			//x2 = (goal[i] + 1) % 3;
			rowComp(x2);

			dx = abs(x - x2);
			y = (i + 1) / 3;
			//dy = abs(y - goalPositions[i]);

			dist += (dx + dy);

		}



		return dist;//tmp val
	}
	inline int getHeuristic(const State &state)
	{
		int cost = 0;

		return 0;
	}

};

