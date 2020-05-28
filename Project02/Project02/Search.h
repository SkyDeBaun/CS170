#pragma once

//CS170 -> Project 02 -> Feature Selection
//Forward Selection Search finds and reports on best (most accurate) subset of features
//Sky DeBaun



#include <vector>


#include "DataParser.h"
#include "NearestNeighborClassifier.h"
#include "Validator.h"

using std::vector;
using std::pair;

typedef double percentage;
typedef vector<double> feature_keys;
typedef pair<feature_keys, percentage> subFeatures;

class Search
{
private:
	DataObject *data;
	NearestNeighborClassifier *classifier;
	Validator *validator;
	vector<subFeatures> best_subFeatures;//store best subfeatures from each search iteration (will return best at end)
	vector<subFeatures> searching_subFeatures;//use and clear for each iteration's


public:
	Search(DataObject *data);
	~Search();

	void findBestFeatures();



};

