#pragma once
//CS170 Project02 -> Sky DeBaun
//converts text file of sample data to doubles (stores in vector passed by reference)

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip> //set precision (debug output)


//using-----------------------------------
using std::vector;
using std::fstream;
using std::string;
using std::ios;
using std::cout;

class DataConvert
{
public:
	bool openFile(fstream &file, const char *name);
	void convertFile(fstream &file, const char *name, vector<double> &numbers, bool debug=false);

private:

};

