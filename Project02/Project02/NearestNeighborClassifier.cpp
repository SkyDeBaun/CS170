#include "NearestNeighborClassifier.h"

//constructor-------------------------------
NearestNeighborClassifier::NearestNeighborClassifier(DataObject *dat) : data(dat)
{
	cols = data->getCols();
	size = data->getSize();
	rows = size / cols;
}

int NearestNeighborClassifier::classifier(size_t instanceNumber, vector<bool> featureKey)//return class given nearest neighbor to instance row
{		
	myQueue.clear(); //using simple vector, will sort after filled... my priority_queue not sorting on push!

	int classID = -1;
	double distance = 0.0;

	for (size_t i = 0; i < rows; ++i)
	{
		if (i != instanceNumber)//skip the row we are comparing to
		{			
			classID = (int)data->getValue(i*cols);
			distance = getDistance(instanceNumber, i, featureKey);
			myQueue.push_back(make_pair(distance, classID));			
		}
	}

	//sort my queue---------------------------
	sort(myQueue.begin(), myQueue.end());	

	return myQueue[0].second;
}



//get distance overide-------------------------
double NearestNeighborClassifier::getDistance(size_t here, size_t there, vector<bool> featureKey)//distance between two given instances(rows)
{
	double accumulator = 0.0;
	size_t hereRow = here * cols;
	size_t thereRow = there * cols;

	//iterate through features (columns)-------
	if (there < rows) //don't want to try to look at/from a non-existant row..
	{
		for (size_t i = 1; i < cols; ++i)//loop for columns (skipping class ID column 0)
		{
			if (featureKey[i])//examine only features selected by key
			{				
				accumulator += pow(data->getValue(i+ hereRow) - data->getValue(i + thereRow), 2);
			}
		}	
	}
	else//give simple error message for invalid input (returns 0.0)
	{
		cout << "Error: specified row outside of valid range \n";
	}

	return accumulator;
}
