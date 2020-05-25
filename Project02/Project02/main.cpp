//CS170 -> Intro to AI -> Project02 -> Nearst Neighbor Classifier -> Sky DeBaun

/*
Text Data File makes these assumptions:
-entries are space delimited
-rows are newline delimited
-the first elements of each row are class identifiers
*/

//includes--------------------------------
#include <iostream>
#include <fstream>
#include <vector>

#include "DataConvert.h"
#include "DataObject.h"

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

	//small data set----------------------------------
	vector <double> smallDataVector;
	DataObject *smallData;
	smallData = new DataObject(smallDataVector);
	conversion.convertFile("data/cs_170_small80.txt", smallData); //parameters: filename, vector, debug = false

	//verify: 
	conversion.printTable(smallData);

	//verify: normalized
	conversion.normalize(smallData);
	conversion.printTable(smallData);


	//large data set----------------------------------
	vector <double> largeDataVector;
	DataObject *largeData;
	largeData = new DataObject(largeDataVector);
	conversion.convertFile("data/cs_170_large80.txt", largeData); //parameters: filename, vector, debug = false
	conversion.normalize(largeData);
	
	//cleanup
	delete smallData;
	delete largeData;

	return 0;

}//end main-------------------------------------------///


//function definitions--------------------------------