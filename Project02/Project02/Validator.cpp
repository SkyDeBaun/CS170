#include "Validator.h"


Validator::Validator(NearestNeighborClassifier *classifier):classifier(classifier)
{
	cout << std::fixed;
	std::setprecision(2);
	cout << "Accuracy: " << (int)(this->validate() * 100.00) << "%\n";
}

double Validator::validate()
{
	DataObject *data = classifier->getData();
	int size = data->getSize();
	size_t cols = data->getCols();
	size_t rows = size / cols;//this could be returned from classifier instead (but would need function)
	int currentClass;
	int successes = 0;
	double accuracy;

	//vector<bool> key(11, true);//tmp key
	vector<bool> key{ false, false,false, true, false, true, false, false, false, false, false };//test key 91%
	//iterate through data----------------------
	for (size_t i = 0; i < rows - 1; ++i)//i represents left out instance here
	{
		currentClass = (int)data->getValue(i*cols);//get Class ID of instance from data (field 0)
		//cout<< classifier->classifier(i,key) << "\n";

		if (currentClass == classifier->classifier(i, key))
		{
			++successes;
			//cout << "Success found: \n";
		}
		else
		{
			//cout << "Missed\n";
		}

	}
	   	 
	accuracy = (double)successes/(double)rows;
	return accuracy;
}
