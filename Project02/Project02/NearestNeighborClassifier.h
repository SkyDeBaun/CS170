#pragma once

//finds nearest neighbor of specified instance (row) for normalized dataset feature

//min-heap (priority queue) example from geeksforgeeks.org
//https://www.geeksforgeeks.org/priority-queue-of-pairs-in-c-with-ordering-by-first-and-second-element/?ref=rp


#include <algorithm>
#include<vector>
#include <queue>
#include <math.h>//for squareroot, pow
//#include <map>

#include "DataObject.h"

using std::min_element;
using std::priority_queue;
//using std::map;
using std::vector;
using std::make_pair;
using std::pair;

typedef pair<double, int> myPair;


class NearestNeighborClassifier
{
private:
	DataObject *data;
	size_t cols; //class ID + features = total # of columns
	size_t size; //number of elements 
	size_t rows; // size/cols

public:
	NearestNeighborClassifier(DataObject *dat);
	int classify(size_t instance);
	double getDistance(size_t here, size_t there);//distance between two given instances(rows)
	
};

