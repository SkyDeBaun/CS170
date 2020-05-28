#include "Validator.h"


Validator::Validator(NearestNeighborClassifier *classifier):classifier(classifier)
{
	//cout << std::fixed;
	//std::setprecision(2);
	//cout << "Accuracy: " << (int)(this->validate() * 100.00) << "%\n";
}

double Validator::validate(vector<bool> &key)
{
	DataObject *data = classifier->getData();
	int size = data->getSize();
	size_t cols = data->getCols();
	size_t rows = size / cols;//this could be returned from classifier instead (but would need function)
	int currentClass;
	int successes = 0;
	double accuracy;

	//vector<bool> key(11, true);//test key 67%
	//vector<bool> key{ false, false,false, true, false, true, false, false, false, false, false };//test key 91%
	
	//iterate through data----------------------
	for (size_t i = 0; i < rows ; ++i)
	{
		currentClass = (int)data->getValue(i*cols);//get Class ID of instance from data (field 0)

		if (currentClass == classifier->classifier(i, key))//does it match nearest neighbor?
		{
			++successes;
		}	
	}
	   	 
	accuracy = (double)successes/(double)rows;
	return accuracy;
}
