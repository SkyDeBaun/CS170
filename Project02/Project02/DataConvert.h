#pragma once
//CS170 Project02 -> Sky DeBaun
//converts text file of sample data to doubles (stores in avector passed by reference)

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

class DataConvert
{
public:
	bool openFile(const char *name);//test for valid file
	void convertFile(const char *name, DataObject *data, bool debug = false);//convert text file to vector of doubles

	void printTable(DataObject *data);
private:
	fstream file;
};

