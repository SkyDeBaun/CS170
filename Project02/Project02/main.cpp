//CS170 Project02 -> Sky DeBaun -> Spring 2020

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




	//large data set----------------------------------
	vector <double> largeDataVector;
	DataObject *largeData;
	largeData = new DataObject(largeDataVector);
	conversion.convertFile("data/cs_170_large80.txt", largeData); //parameters: filename, vector, debug = false

	
	//cleanup
	delete smallData;
	delete largeData;

	return 0;

}//end main-------------------------------------------///


//function definitions--------------------------------