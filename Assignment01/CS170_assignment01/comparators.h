#pragma once


#include"Node.h"
#include "distance.h"

//wtf GIT?




class AStar_Comparator
{
private:
	Distance distance;//holds comparision and distance utilities

public:
	bool operator()(const Node* n1, const Node* n2)
	{

		const State& state1 = n1->returnState();
		int cost1 = distance.getManhattanDistance(state1) + distance.getHeuristic(state1);

		const State& state2 = n2->returnState();
		int cost2 = distance.getManhattanDistance(state2) + distance.getHeuristic(state2);

		return cost1 > cost2;

	}//end bool operator---//

};

class Greedy_Comparator
{
public:


};

