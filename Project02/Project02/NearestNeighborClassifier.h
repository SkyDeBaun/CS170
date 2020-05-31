#pragma once

//finds nearest neighbor of specified instance (row) for normalized dataset feature


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
	vector<myPair> myQueue;//cheap fix for priority_queue mis-sorting issue
	size_t cols; //class ID + features = total # of columns
	size_t size; //number of elements 
	size_t rows; // size/cols

public:
	NearestNeighborClassifier(DataObject *dat);
	int classifier(size_t instance, vector<bool> &featureKey);//parameter represents instance (row) to find nearest neighbor of -> used for training
	int getClass(size_t k=1);
	double getDistance(size_t here, size_t there, vector<bool> &featureKey);//distance between two given instances(rows)
	DataObject* getData();
};

//pass feature key by ref!!