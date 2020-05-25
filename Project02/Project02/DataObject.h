#pragma once

#include <vector>
using std::vector;


class DataObject
{
private:
	int columns;
	vector<double> &data;


public:
	DataObject(vector<double> &vec):data(vec)
	{
		
	}
	DataObject(vector<double> &vec, int cols) : data(vec), columns(cols)
	{

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

	vector<double>& getData()
	{
		return data;
	}
	   

};