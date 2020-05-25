#pragma once

#include <algorithm>
#include<vector>
#include <queue>
#include <math.h>//for squareroot, pow
#include <map>

#include "DataObject.h"

using std::min_element;
using std::priority_queue;
using std::map;
using std::vector;
using std::make_pair;


class NearestNeighborClassifier
{
private:
	DataObject *data;


public:
	NearestNeighborClassifier(DataObject *dat);
	int classify(size_t instance);
	double getDistance(size_t here, size_t there);//distance between two given instances(rows)
	


};

