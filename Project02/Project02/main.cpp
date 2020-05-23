//CS170 Project02 -> Sky DeBaun -> Spring 2020

//includes--------------------------------
#include <iostream>
#include <fstream>
#include <vector>

#include "DataConvert.h"


//using-----------------------------------
using std::vector;
using std::cout;


//function prototypes----------------------



//MAIN------------------------------------------------
//----------------------------------------------------
int main()
{
	//convert sample data set to numeric values-------
	DataConvert conversion; //data conversion object converts sample data

	vector <double> smallDataSet;
	conversion.convertFile("data/cs_170_small80.txt", smallDataSet, true); //parameters: filename, vector, debug = false

	vector <double> largeDataSet;
	conversion.convertFile("data/cs_170_large80.txt", largeDataSet); //parameters: filename, vector, debug = false

	
	return 0;

}//end main-------------------------------------------///


//function definitions--------------------------------