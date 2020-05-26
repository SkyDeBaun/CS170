#pragma once
//CS170 -> Intro to AI -> Project02 -> Nearest Neighbor Classifier -> Sky DeBaun
//parses text file (feature data set) and stores a normalized data set in DataObject (vector member)

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip> //set precision (for debug output)

#include "DataObject.h"


//using-----------------------------------
using std::vector;
using std::fstream;
using std::string;
using std::ios;
using std::cout;

class DataParser
{
public:
	bool openFile(const char *name);//test for valid file stream
	void parseDataFile(const char *name, DataObject *data, bool debug = false);//convert text file with data set to DataObject
	void normalize(DataObject *data);//calls functions in DataObject class
	void printTable(DataObject *data);

private:
	fstream file;
};

