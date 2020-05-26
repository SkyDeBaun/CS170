#pragma once
//CS170 -> Project02 -> Sky DeBaun
//leave-one-out validator uses training data and classifier to find and return accuracy of subset of features

#include "DataObject.h"
#include "NearestNeighborClassifier.h"


class Validator
{
private:
	DataObject *data;
	NearestNeighborClassifier *classifier;
	vector<bool> *subset;//boolean key identifies feature subset (of DataObject) to classify

public:
	Validator();
	double getAccuracy();

};

