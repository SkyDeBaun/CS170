#include "Validator.h"


Validator::Validator(NearestNeighborClassifier *classifier):classifier(classifier)
{	
}

//validator returns accuracy of select set of features
//vector<bool> key tracks selected features
double Validator::validate(vector<bool> &key)
{
	DataObject *data = classifier->getData();
	int size = data->getSize();
	size_t cols = data->getCols();
	size_t rows = size / cols;
	int currentClass;
	int successes = 0;
	double accuracy;
	

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
