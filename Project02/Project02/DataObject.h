//CS170 -> Sky DeBaun
//DataObject encapsulates data and normalization functionality
#pragma once

#include <iostream>
#include <vector>
#include <math.h>//for squareroot, pow

using std::vector;
using std::cout;

class DataObject
{
private:
	int columns;
	vector<double> &data;
	double preNormalAverage; 
	double standardDeviation;
	bool normalized; //used to protect allready normalized data set


public:
	DataObject(vector<double> &vec):data(vec)
	{
		normalized = false;
	}
	DataObject(vector<double> &vec, int cols) : data(vec), columns(cols)
	{
		normalized = false;
	}
	void updateCols(int cols)
	{
		this->columns = cols;
	}
	void pushData(double val)
	{
		data.push_back(val);
	}
	int getCols()
	{
		return columns;
	}
	int getSize()
	{
		return data.size();
	}
	double getValue(int i)
	{
		return data[i];
	}	
	double getAverage()
	{
		return preNormalAverage;
	}
	double getStandardDeviation()
	{
		return standardDeviation;
	}
	bool getNormalizedStatus()
	{
		return normalized;
	}
	vector<double>& getData()
	{
		return data;
	}
	

	//calculate average of all values in data set---------------
	void calcAverage()
	{
		size_t size = data.size(); //total # of elements
		double accumulator = 0;
		int rows = size / columns;

		for (size_t i = 0; i < size; ++i)
		{
			if (i%columns != 0)
			{
				accumulator += data[i];
			}
		}
		preNormalAverage = accumulator / (rows * (columns - 1));
		cout << "AVG: " << preNormalAverage << std::endl;//debug->verify expected value

	}//end calcAverage---//

	//calculate standard deviation of all values in data set----
	void calcStandardDeviation()
	{
		size_t size = data.size(); //total # of elements
		double accumulator = 0;
		int rows = size / columns;

		for (size_t i = 0; i < size; ++i)
		{
			if (i%columns != 0)
			{
				accumulator += pow(data[i] - preNormalAverage, 2);
			}
		}
		standardDeviation = sqrt(accumulator/ (rows * (columns - 1)));
		cout << "Standard Deviation: " << standardDeviation << "\n"; //debug-> verify expected value

	}//end calcStandardDeviation---//

	//normalize the data set-------------------------------------
	void normalize()
	{
		if (!normalized)//lets not do this again (in case called more than once-> ie from main for print verification)
		{
			size_t size = data.size(); //total # of elements

			for (size_t i = 0; i < size; ++i)
			{
				if (i%columns != 0)
				{
					data[i] = (data[i] - preNormalAverage) / standardDeviation;
				}
			}

			normalized = true; //set flag
		}		

	}//end normalize---//

};