//CS170 -> Intro to AI -> Project02 -> Nearst Neighbor Classifier 
//Sky DeBaun

/*
Valid Text Data Files make the following asumptions:
-entries are space delimited characters representing numerals
-rows are newline delimited
-the first newline character determines total # of columns in the dataset
-the first element of each row *are class identifiers, then:
-the following elements are class features (I accept variable # of feature columns automagically)
-data stored in one 1D vector within DataObject class
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
	cout << "Small Dataset: ";
	vector <double> smallDataVector;
	DataObject *smallData;
	smallData = new DataObject(smallDataVector);
	conversion.parseDataFile("data/cs_170_small80.txt", smallData, true); //parameters: filename, vector, debug = false
	conversion.printTable(smallData); //debug -> verify: normalized


	//large data set----------------------------------
	cout<< "\n" << "Large Dataset: ";
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