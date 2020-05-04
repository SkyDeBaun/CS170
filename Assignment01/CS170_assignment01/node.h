//Nodes for tree construction
#include "state.h"

#pragma once
class Node
{
protected:
	State puzzleState;
	int branchDepth;//using state to hold depth instead
	const Node* parent; 

public:
	//constructor initializes with 
	Node(const State &puzzleState, const Node *parent, int depth=0) 
		: parent(parent), branchDepth(depth), puzzleState(puzzleState)
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

	const Node* getParent() const
	{
		return parent;
	}

	int getDepth() const
	{
		return branchDepth;
	}

	void print() const
	{
		puzzleState.printState();
	}

	const State& returnState()const
	{
		return puzzleState;
	}
	
	int returnEmptyTile() //return index of empty puzzle tile
	{
		return puzzleState.findEmptyTile();
	}
};

