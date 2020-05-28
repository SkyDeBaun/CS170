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
	//test validator----------------------------
	//vector<bool> key{ false, false,false, true, false, true, false, false, false, false, false };//test key 91%
	//cout << "Accuracy: " << validator->validate(key) << "\n";//test

	size_t cols = data->getCols();
	vector<bool> key_tracker(cols, false);//always skip the first column (class ID)
	//vector<bool> key_tracker;//hold temp keys
	bool newFlag = false;
		

	for (size_t j = 1; j < cols; ++j)
	{
		for (size_t i = 1; i < cols; ++i)
		{
			if (key_tracker[i] == false)
			{
				key_tracker[i] = true;
				//cout << "Accuracy: " << validator->validate(key_tracker) << "\n";//test
				searching_subFeatures.push_back(make_pair(validator->validate(key_tracker), key_tracker));
				key_tracker[i] = false;
			}
		}

		sort(searching_subFeatures.begin(), searching_subFeatures.end());//sort for current best
		best_subFeatures.push_back(searching_subFeatures.back());//get the highest from current and add to best set of features
		searching_subFeatures.clear();//reset for next iteration

		key_tracker = best_subFeatures[best_subFeatures.size()-1].second;//copy best from previous search
	}

	//sort at end for best feature combination-------------
	sort(best_subFeatures.begin(), best_subFeatures.end());//re-sort for best
	printReport();
}

void Search::printReport()
{
	cout << "\n" << "Most Accurate Sub-Features: \n";

	cout << "Percent:\t" << "Features\n";

	size_t size = best_subFeatures.size();
	double accuracy = 0;

	for (size_t i = size -1; i > 0; --i)
	{
		cout << best_subFeatures[i].first << ":\t";
		printFeatureNumbers(best_subFeatures[i].second);
		cout << "\n";
	}
}

void Search::printFeatureNumbers(vector<bool> &features)
{
	for (size_t i = 1; i < best_subFeatures.size(); ++i)
	{
		if (features[i])
		{
			cout << i << "\t";
		}
	}
}