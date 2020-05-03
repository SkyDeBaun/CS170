#pragma once

#include<vector>
#include <map>

using std::map;
using std::vector;
using std::make_pair;


class Operators
{
protected:
	map<int, vector<int>> possibleMoves;//map index of blanc to possible moves

	//create mapped dictionary of possible moves (from "blanc" ie 0 position)
	//consider -> create this programatically with some modulo operations
	void createMoveMap()//the nine positions for eight puzzle
	{
		//map index to vector of possible moves
		possibleMoves.insert(make_pair(0, vector<int>{1, 3}));
		possibleMoves.insert(make_pair(1, vector<int>{0, 2, 4}));
		possibleMoves.insert(make_pair(2, vector<int>{1, 5}));
		possibleMoves.insert(make_pair(3, vector<int>{4, 0, 6}));
		possibleMoves.insert(make_pair(4, vector<int>{3, 5, 1, 7}));
		possibleMoves.insert(make_pair(5, vector<int>{4, 2, 8}));
		possibleMoves.insert(make_pair(6, vector<int>{7, 3}));
		possibleMoves.insert(make_pair(7, vector<int>{6, 8, 4}));
		possibleMoves.insert(make_pair(8, vector<int>{7, 5}));

	}//end createMoveMap---//

public:
	//default constructor-------------------------------
	//consider -> constructor for programatic construction of possible moves
	Operators()
	{
		createMoveMap();
	}
	
	//get possible moves from blanc(index) position-----
	const vector<int> &getPossibleMoves(int index) const
	{
		map<int, vector<int>>::const_iterator itr(possibleMoves.find(index));
		if (itr != possibleMoves.end())
		{
			return itr->second;//return vector of possible moves
		}
		//none found
		vector<int> empty;
		return empty;

	}//end getPossibleMoves---//

};

