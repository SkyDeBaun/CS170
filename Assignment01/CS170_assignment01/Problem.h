//creates tree for node expansion and solution discovery
#pragma once

#include <algorithm>    // std::min_element, std::max_element
#include <queue>

#include "node.h"
#include "state.h"
#include "operators.h"
#include "comparators.h"

using std::min_element;
using std::priority_queue;


class Problem
{
protected:
	enum algorithmType { AStar, Greedy } algorithm;
	vector<const Node*> frontier;
	priority_queue<const Node*, vector<const Node*>, AStar_Comparator> pq_frontier;

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
		problemSolved = false;

		//switch based on algorithm type-----------------------
		switch (algorithm)
		{
			case AStar:
			{
				pq_frontier.push(rootNode);
			}
			case Greedy:
			{
				frontier.push_back(rootNode); //add root to frontier
			}

		}//end switch---//

	}
	~Problem()
	{
		
	}



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
						
		//algorithm selection----------------------------
		switch (algorithm)
		{
			case AStar:
			{				
				if (!pq_frontier.empty())
				{
					//move Node from frontier to visited------
					currentNode = pq_frontier.top();
					explored.push_back(currentNode);
					pq_frontier.pop();
				}				
				break;

			}//end case AStar---//

			case Greedy:
			{

			}

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
					//const Node* nod = nullptr;

					++depth;//depth of next generation of nodes
					const Node *node(new Node(currentState, currentNode, depth)); //create new node

					//switch based on algorithm type-----------------------
					switch (algorithm)
					{
						case AStar:
						{
							pq_frontier.push(node);
							break;
						}
						case Greedy:
						{
							frontier.push_back(node);
							break;
						}

					}//end switch---//

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
				node = node->getParent();
			} while (node != nullptr);

		}//end if---//

		//print solution----------------------------------------
		cout << "\n" << "The Solution: \n\n";

		for (int i = solution.size()-1; i >-1; --i)
		{
			solution[i]->print();
			cout << "\n";
		}

	}//end solve---//

};


