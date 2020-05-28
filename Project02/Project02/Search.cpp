#include "Search.h"


Search::Search(DataObject *dat):data(dat)
{
	classifier = new NearestNeighborClassifier(data);
	validator = new Validator(classifier);
}
Search::~Search()
{
	delete classifier;
	delete validator;
}

void Search::findBestFeatures()
{
	vector<bool> key{ false, false,false, true, false, true, false, false, false, false, false };//test key 91%
	cout << "Accuracy: " << validator->validate(key) << "\n";//test
}
