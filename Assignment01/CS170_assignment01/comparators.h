#pragma once

#include <random>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include"Node.h"


//wtf GIT?



inline int getManhattanDistance(const State &state)
{
	int dist = 0;
	srand(time(NULL));
	dist = state.returnState(0);//tmp test

	//tmp
	dist = rand() & 100;

	return dist;//tmp val
}
inline int getHeuristic(const State &state)
{
	int cost = 0;

	return 0;
}


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

