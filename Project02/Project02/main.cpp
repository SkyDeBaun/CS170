//CS170 -> Intro to AI -> Project02 -> Nearst Neighbor Classifier -> Sky DeBaun

/*
Text Data File makes these asumptions:
-entries are space delimited
-rows are newline delimited
-the first elements of each row are class identifiers
-the next elements are class features (I accept variable # of features automatically)
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
	conversion.parseDataFile("data/cs_170_small80.txt", smallData, true); //parameters: filename, vector, debug = false
	conversion.printTable(smallData); //debug -> verify: normalized


	//large data set----------------------------------
	vector <double> largeDataVector;
	DataObject *largeData;
	largeData = new DataObject(largeDataVector);
	conversion.parseDataFile("data/cs_170_large80.txt", largeData); //parameters: filename, vector, debug = false



	//cleanup-----------------------------------------
	delete smallData;
	delete largeData;

	return 0;

}//end main-------------------------------------------///


//function definitions--------------------------------