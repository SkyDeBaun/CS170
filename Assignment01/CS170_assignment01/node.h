//Nodes for tree construction
#include "state.h"

#pragma once
class Node
{
protected:
	State puzzleState;
	int branchDepth;
	Node* parent; 

public:
	//constructor initializes with 
	Node(const State &puzzleState, Node *parent, int depth) 
		: branchDepth(depth), puzzleState(puzzleState)
	{
		parent = parent;//freaky
	}
		
	~Node()
	{
		delete parent;
	}

	void setParent(Node *node)
	{
		parent = node;
	}

	Node* getParent()
	{
		return parent;
	}

	int getDepth() const
	{
		return branchDepth;
	}

	void print() const
	{
		int size = puzzleState.returnSize();

		for (size_t i = 0; i < size; ++size)
		{
			cout << puzzleState.returnState(i) << " \n";
		}
	}

	const State& returnState()const
	{
		return puzzleState;
	}
};

