//creates tree for problem
#pragma once

#include <algorithm>    // std::min_element, std::max_element

#include "node.h"
#include "state.h"
#include "operators.h"

using std::min_element;


class Problem
{
protected:
	enum algorithmType { AStar } algorithm;
	vector<Node*> frontier;
	vector<Node*> explored;
	State& goal;
	bool problemSolved;
	algorithmType algoType;
	Operators operators;

public:
	Problem(const State &_start,  State &_goal, const Operators &_operators, algorithmType = AStar) : goal(_goal), operators(_operators) ,algoType(AStar)
	{
		//initialize with root node
		Node* rootNode(new Node(_start, nullptr, 0));
		frontier.push_back(rootNode); //add root to frontier
		problemSolved = false;
	}


	int getManhattanDistance(const State &state)
	{
		int dist = 0;
		dist = state.returnState(0);//tmp test

		return dist;//tmp val
	}
	int getHeuristic(const State &state)
	{
		int cost = 0;

		return 0;
	}


	bool operator()(const Node* n1, const Node* n2) 
	{
		const State& state1 = n1->returnState();
		int cost1 = getManhattanDistance(state1) + getHeuristic(state1);

		const State& state2 = n2->returnState();
		int cost2 =  getManhattanDistance(state2) + getHeuristic(state2);

		return cost1 < cost2;
	}

	
	Node* traverseFrontier()
	{
		if (frontier.empty())
		{
			return nullptr;
		}

		//create pointer to current node-----------------
		Node* currentNode;


		//algorithm selection----------------------------
		switch (algorithm)
		{
			case AStar:
			{
				//create iterator for frontier-----------
				vector<Node*>::iterator itr(min_element(frontier.begin(), frontier.end()));

				//check frontier-------------------------
				if (itr == frontier.end())
				{
					return 0;
				}

				//move Node from frontier to visited------
				currentNode = *itr;
				explored.push_back(currentNode);
				frontier.erase(itr);

				break;

			}//end case AStar---//

			//return pointer to current node--------------
			return currentNode;

		}//end switch---//

	}//end traverseFrontier---//



	//expand nodes------------------------------------------------
	void expandNodes(const Node *_node, const Operators &_operators)
	{

	}


	//solve problem for solution----------------------------------
	void solve()
	{
		while (!problemSolved)
		{
			Node* currentNode = traverseFrontier();
			expandNodes(currentNode, operators);

		}
	}//end solve---//

};


