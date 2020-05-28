#include "NearestNeighborClassifier.h"

//constructor-------------------------------
NearestNeighborClassifier::NearestNeighborClassifier(DataObject *dat) : data(dat)
{
	cols = data->getCols();
	size = data->getSize();
	rows = size / cols;
}

int NearestNeighborClassifier::getClass(size_t k)
{
	//hardcoded for two class types: 1, 2
	int one = 0;
	int two = 0;
	vector<int> counter;

	//skim off the top of the queue
	 for (size_t i = 0; i < k; ++i)
	 {
		 counter.push_back(myQueue[i].second);
	 }

	 //count instances
	 one = std::count(counter.begin(), counter.end(), 1);
	 two = std::count(counter.begin(), counter.end(), 2);

	 if (one > two)
	 {
		 return 1;
	 }
	 return 2;		
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

	return getClass(1);//return nearest neighbor's class (can acommodate variable k parameters)
}



//get distance overide-------------------------
double NearestNeighborClassifier::getDistance(size_t here, size_t there, vector<bool> featureKey)//distance between two given instances(rows)
{
	double accumulator = 0.0;
	int columns = data->getCols();
	size_t hereRow = here * columns;
	size_t thereRow = there * columns;

	//iterate through features (columns)-------
	if (there < rows) //don't want to try to look at/from a non-existant row..
	{
		for (size_t i = 1; i < columns; ++i)//loop for columns (skipping class ID column 0)
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



DataObject* NearestNeighborClassifier::getData()
{
	return data;
}
