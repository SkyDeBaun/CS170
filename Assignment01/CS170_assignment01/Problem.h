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
	vector<const Node*> frontier;
	vector<const Node*> explored;
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
	~Problem()
	{
		
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

	}//end bool operator---//


	bool inState(const State &state, const vector<const Node*> nodes)
	{
		for (size_t i = 0; i < nodes.size(); ++i)
		{
			if (state == nodes[i]->returnState())
			{
				return true;
			}
		}
		return false;

	}//end inState---//

	//traverse the frontier and place Nodes into explored-----------------
	const Node* traverseFrontier()
	{
		//create pointer to current node-----------------
		const Node* currentNode = nullptr; 

		if (frontier.empty())
		{
			return currentNode;
		}
				
		//algorithm selection----------------------------
		switch (algorithm)
		{
			case AStar:
			{
				//create iterator for frontier-----------
				vector<const Node*>::iterator itr(min_element(frontier.begin(), frontier.end()));

				//check frontier-------------------------
				if (itr == frontier.end())
				{
					return 0;
				}

				//move Node from frontier to visited------
				currentNode = *itr;
				explored.push_back(currentNode);
				frontier.erase(itr); //

				break;

			}//end case AStar---//

			//return pointer to current node--------------
			

		}//end switch---//

		return currentNode;

	}//end traverseFrontier---//



	//expand nodes of tree-----------------------------------------------
	void expandNodes(const Node *currentNode)
	{
		if (currentNode == nullptr)
		{
			//oops
			return;
		}

		if (currentNode->returnState() == this->goal)
		{
			problemSolved = true; //well... goal state found
			return; //return with goal in currentNode
		}
		else
		{
			int emptyTile = currentNode->returnState().findEmptyTile(); //get position of blanc (ie empty) tile
			int depth = currentNode->returnState().returnDepth();
			const vector<int> &ops = operators.getPossibleMoves(emptyTile); //return vector of possible moves

			//iterate through ops for retuned moves------------------------
			for (int move : ops)
			{
				State currentState = currentNode->returnState();
				currentState.swapTiles(emptyTile, move);//swap positions with an operator (move)

				//construct the tree of new nodes--------------------------				
				if (!inState(currentState, explored)) //construct tree on exit (placed into explored)
				{
					const Node* nod = nullptr;

					++depth;//depth of next generation of nodes
					const Node *node(new Node(currentState, currentNode, depth)); //create new node
					frontier.push_back(node);

				}//end if---//

			}//end for---//

		}//end if else---//

	}//endexpandNodes---//


	//solve problem for solution----------------------------------
	void solve()
	{
		const Node* currentNode = nullptr;
		const Node* node = nullptr;
		vector<const Node*> solution;


		while (!problemSolved) //compare against explored
		{
			currentNode = traverseFrontier();//traverse and move current Node to explored
			expandNodes(currentNode); //expand current Node's children
		}

		

		//not solved.. but goal state found--------------------
		if (problemSolved)
		{	
			node = currentNode;

			//add current and all parent Nodes to solution-----
			do
			{
				solution.push_back(node);
				node = currentNode->getParent();
			} while (node != nullptr);

		}//end if---//

		//print solution----------------------------------------
		cout << "\n" << "The Solution: \n";

		for (int i = solution.size()-1; i >-1; --i)
		{
			solution[i]->print();
		}

	}//end solve---//

};


