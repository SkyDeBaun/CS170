#pragma once

#include <random>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>       /* round, floor, ceil, trunc */

#include "state.h"
#include <map>

using std::map;
using std::make_pair;



class Distance
{

protected:
	vector<int> myGoal = { 1, 2, 3, 4, 5, 6, 7, 8, 0 }; //duplicating goal state for eight-puzzle->lame!; //cheesy hack...should be avoided -> running into circular dependency issue!!
	map<int, int> goalPositions;
	map<int, int> currentPositions;
	map<int, int> missingPositions;

	int dx;
	int dy;

	int x;
	int x2;
	int y;
	int y2;
	int xPosition;
	int x2Position;

public:

	Distance()
	{
		//populate maps with index-val pair--------------------
		for (size_t i = 0; i < myGoal.size(); ++i)
		{
			goalPositions.insert(make_pair(myGoal[i], i));//make map of value-position pair
			missingPositions.insert(make_pair(i,myGoal[i]));//make map
		}
	}

	//some function declarations... all should be like this
	inline void findDistance(const State &state, int &dx, int &dy, int i);
	inline int misplacedHeuristic(const State &state);



	inline int returnUniformDistance()
	{
		return 1;
	}

	inline void columnComp(int &val)
	{
		if (val == 0)
		{
			val = val + 3;
		}
	}
	inline void rowComp(int &val)
	{
		if (val == 0)
		{
			val = val + 1;
		}
	}
		
	
	inline int getManhattanDistance(const State &state)
	{
		int size = state.returnSize();// state.returnSize(); //get number of elements
		int dist = 0;//reset this shared va
		currentPositions.clear();

		for (size_t i = 0; i < size; ++i)
		{
			currentPositions.insert(make_pair(i, state.returnState(i)));//populate map with index val pair
			findDistance(state, dx, dy, i);
			dist += (dx + dy);//sum the total value

		}//end for i---//
		
		//cout << "Dist: " << dist << " \n";
		return dist;
	}//end getManhatten---//

	inline int getUniformDistance(const State &state)
	{
		int cost = state.returnDepth();
	}


	

	inline double getEuclidean(const State &state)
	{
		int size = state.returnSize();// state.returnSize(); //get number of elements
		double euclidsDistance = 0.0;
		currentPositions.clear();

		for (size_t i = 0; i < size; ++i)
		{
			currentPositions.insert(make_pair(i, state.returnState(i)));
			findDistance(state, dx, dy, i);
			euclidsDistance += sqrt(dx + dy);//sum the total value

		}//end for i---//

		return euclidsDistance;
	}

};


 void Distance::findDistance(const State &state, int &dx, int &dy, int i)
{
	int size = state.returnSize();// state.returnSize(); //get number of elements
			
		x = currentPositions.find(i)->second;//get value at index i
		x2 = goalPositions.find(x)->second;//get goal position of the value

		y = ceil((i + 1) / 3.0);//current row	
		y2 = ceil((x2 + 1) / 3.0);//goal row		

		xPosition = (i + 1) % 3;//gives columns 0, 1, 2
		columnComp(xPosition);//corrects columns to 1, 2, 3

		x2Position = (x2 + 1) % 3;
		columnComp(x2Position);//compensate for 0 index start

		dx = abs(xPosition - x2Position);
		dy = abs(y - y2);

}//end findDistance---//




 int Distance::misplacedHeuristic(const State &state)
 {
	 int size = state.returnSize();// state.returnSize(); //get number of elements
	 int counter=0;
	 	 
	 for (int i = 0; i < size; ++i)
	 {
		 currentPositions.insert(make_pair(i, state.returnState(i)));//populate map with index val pair	 
		 x = currentPositions.find(i)->second;//get value at index i
		 x2 = missingPositions.find(i)->second;//get goal position of the value

		 if (x != x2)
		 {
			 ++counter;
		 }
	 }

	 return counter;

 }//end misplacedHeuristic---//