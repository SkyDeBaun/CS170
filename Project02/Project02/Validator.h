#pragma once
//CS170 -> Project02 -> Sky DeBaun
//leave-one-out validator uses training data and classifier to find and return accuracy of subset of features

#include <iomanip> //set precision (for debug output)


#include "DataObject.h"
#include "NearestNeighborClassifier.h"


class Validator
{
private:
	NearestNeighborClassifier *classifier;

public:
	Validator(NearestNeighborClassifier *classifier);
	double validate(vector<bool> &key);

};

