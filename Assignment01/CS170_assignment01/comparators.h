//comparators -> manahattan distance and heuristic calculation
#pragma once

#include <random>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "node.h"
#include "operators.h"
#include <map>

using std::map;
using std::make_pair;


inline void rowComp(int &val)
{
	if (val == 0)
	{
		val = val+3;
	}	
}


//manhattan distance calculator-----------------------
inline int getManhattanDistance(const State &state)
{
	int size = state.returnSize();// state.returnSize(); //get number of elements
	int x;
	int x2;
	int y;
	int y2;
	int dx;
	int dy=0;
	int dist=0;

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



	//int dist0;
	//srand(time(NULL));//for testing this prevented error... think it was two nodes with same value?
	//dist = state.returnState(0);//tmp test

	////tmp value for comparitor
	//dist = rand() & 100;

	return dist;//tmp val
}


inline double getEuclideanDistance()
{
	
}



//heuristic calculator--------------------------------
inline int getHeuristic(const State &state)
{
	int cost = 0;

	return 0;
}

//comparator used by priority_queue -> ie AStar-------
class AStar_Comparator
{
public:
	bool operator()(const Node* n1, const Node* n2)
	{
		const State& state1 = n1->returnState();
		int cost1 = getManhattanDistance(state1) + getHeuristic(state1);

		const State& state2 = n2->returnState();
		int cost2 = getManhattanDistance(state2) + getHeuristic(state2);

		return cost1 < cost2;

	}//end bool operator---//

};

class Greedy_Comparator
{
public:


};

