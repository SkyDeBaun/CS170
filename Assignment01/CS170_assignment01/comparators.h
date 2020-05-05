#pragma once


#include"Node.h"
#include "distance.h"

//wtf GIT?




class AStar_Misplaced
{
private:
	Distance distance;//holds comparision and distance utilities
	int heuristic;

public:
	bool operator()(const Node* n1, const Node* n2)
	{

		const State& state1 = n1->returnState();
		heuristic = distance.misplacedHeuristic(state1);
		int cost1 = n1->returnState().returnDepth() + heuristic;

		const State& state2 = n2->returnState();
		heuristic = distance.misplacedHeuristic(state2);
		int cost2 = n2->returnState().returnDepth() + heuristic;

		return cost1 > cost2;

	}//end bool operator---//

};

class UniformCost
{
private:
	Distance distance;//holds comparision and distance utilities

public:
	bool operator()(const Node* n1, const Node* n2)
	{

		//const State& state1 = n1->returnState();
		int cost1 = n1->returnState().returnDepth();

		//const State& state2 = n2->returnState();
		int cost2 = n2->returnState().returnDepth();

		return cost1 > cost2;

	}//end bool operator---//

};

class EuclideanCost
{
private:
	Distance distance;//holds comparision and distance utilities

public:
	bool operator()(const Node* n1, const Node* n2)
	{

		const State& state1 = n1->returnState();
		int cost1 = n1->returnState().returnDepth() + distance.getEuclidean(state1);

		const State& state2 = n2->returnState();
		int cost2 = n2->returnState().returnDepth() + distance.getEuclidean(state2);

		return cost1 > cost2;

	}//end bool operator---//

};

