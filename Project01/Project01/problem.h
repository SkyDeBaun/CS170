//creates tree for node expansion and solution discovery
#pragma once

#include <algorithm>    // std::min_element, std::max_element
#include <queue>

#include "node.h"
#include "state.h"
#include "operators.h"
#include "comparators.h"
#include "distance.h"

using std::min_element;
using std::priority_queue;



class Problem
{
protected:
	vector<const Node*> frontier;
	priority_queue<const Node*, vector<const Node*>, AStar_Misplaced> pq_frontier;
	priority_queue<const Node*, vector<const Node*>, UniformCost> uniform_frontier;
	priority_queue<const Node*, vector<const Node*>, EuclideanCost> euclidean_frontier;

	vector<const Node*> explored;
	//enum algorithmType { AStar, Uniform, Euclidean } algorithm;

	State& goal;
	bool problemSolved;
	//algorithmType algoType;
	Operators operators;
	int algoChoice;
	Distance distance;

	int totalNodes;
	int nodesExplored;
	int maxNodesInQueue;
	int currentNodesInQueue;


public:
	Problem(const State &_start,  State &_goal, const Operators &_operators, int algo = 1) : goal(_goal), operators(_operators) ,algoChoice(algo)
	{
		//initialize with root node
		Node* rootNode(new Node(_start, nullptr, 0));
		problemSolved = false;

		//switch based on algorithm type-----------------------SWITCH puts rootNode into priority queue
		//note: doing this due to need to pass class to priority queue constructor... not optimal method!
		switch (algoChoice)
		{
			case 2://A* misplaced
			{
				pq_frontier.push(rootNode);
				break;
			}
			case 1:
			{
				uniform_frontier.push(rootNode);
				break;
			}
			case 3:
			{
				euclidean_frontier.push(rootNode);
				break;
			}

			++maxNodesInQueue;

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
		switch (algoChoice)
		{
			case 2://A*
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

			case 1://uniform frontier
			{
				
					if (!uniform_frontier.empty())
					{
						//move Node from frontier to visited------
						currentNode = uniform_frontier.top();
						explored.push_back(currentNode);
						uniform_frontier.pop();
					}
				break;
			}
			case 3:
			{
				;
				if (!euclidean_frontier.empty())
				{
					//move Node from frontier to visited------
					currentNode = euclidean_frontier.top();
					explored.push_back(currentNode);
					euclidean_frontier.pop();
				}
				break;
			}

			--maxNodesInQueue;

		}//end switch---//

		return currentNode;

	}//end traverseFrontier---//



	//expand nodes of tree-----------------------------------------------
	void expandNodes(const Node *currentNode)
	{
		if (currentNode == nullptr)
		{
			//no solution---------------???
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
			const vector<int> &ops = operators.getPossibleMoves(emptyTile); //return vector of possible moves

			int depth;
			//iterate through ops for retuned moves------------------------
			for (int move : ops)
			{
				depth = currentNode->returnBranchDepth();//"reset" the depth here
				State currentState = currentNode->returnState();
				currentState.swapTiles(emptyTile, move);//swap positions with an operator (move)

				//construct the tree of new nodes--------------------------	AVOIDS DUPLICAT STATES (infinit loops)			
				if (!inState(currentState, explored)) //construct tree on exit (placed into explored)
				{
					//const Node* nod = nullptr;

					++depth;//depth of next generation of nodes
					const Node *node(new Node(currentState, currentNode, depth)); //create new node
					cout << depth << endl;//debug---!!!!!!


					++totalNodes;//total nodes expanded into frontier
					

					//switch based on algorithm type-----------------------
					switch (algoChoice)
					{
						case 2:
						{
							pq_frontier.push(node);
							break;
						}
						case 1:
						{
							uniform_frontier.push(node);
							break;
						}
						case 3:
						{
							euclidean_frontier.push(node);
							break;
						}

						++maxNodesInQueue;

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
		int nodesInSolution = 0;


		for (int i = solution.size()-1; i >-1; --i)
		{
			
			cout << "\n" << "g(n) = " << solution[i]->getDepth()<<  "\n";
			solution[i]->print();
			cout << "\n";
			++nodesInSolution;
		}

		cout << "The total number of Nodes created: " << totalNodes << "\n";
		//cout << "The Max number of Nodes in the Queue: " << euclidean_frontier.size() << "\n";
		cout << "The total number of Nodes in solution: " << nodesInSolution << "\n\n";

	}//end solve---//

};


