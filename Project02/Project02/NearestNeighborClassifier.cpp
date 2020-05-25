#include "NearestNeighborClassifier.h"


NearestNeighborClassifier::NearestNeighborClassifier(DataObject *dat) : data(dat)
{

}

int NearestNeighborClassifier::classify(size_t instance)//return class given k nearest neighbors
{
	size_t cols = data->getCols();
	size_t size = data->getSize();
	size_t rows = size / cols;

	int classID = -1;
	double distance = 0.0;


	for (size_t i = 0; i < rows; ++i)
	{
		if (i != instance)//skip the row we are comparing to (for training)
		{
			classID = (int)data->getValue(i*cols);
			distance = getDistance(instance, i);

			//create a pair -> put in queue

		}

	}

	//pop k instances off top of priority queue for nearest neighbor



	return 0;
}

double NearestNeighborClassifier::getDistance(size_t here, size_t there)//distance between two given instances(rows)
{
	size_t cols = data->getCols();
	size_t size = data->getSize();
	size_t rows = size/cols;

	double accumulator = 0.0;
	size_t hereRow = here * cols;
	size_t thereRow = there * cols;
	
	//iterate through features (columns)-------
	if ((here  < rows-1) && (there < rows-1)) //don't want to try to look at/from a non-existant row..
	{
		for (size_t i = 1; i < cols; ++i)//loop for columns (skipping class ID column 0)
		{
			accumulator += pow(data->getValue(i + hereRow) - data->getValue(i + thereRow), 2);
		}
	}
	else//give simple error message for invalid input (returns 0.0)
	{
		cout << "Error: specified row outside of valid range \n";
	}
	
	return accumulator;
}
