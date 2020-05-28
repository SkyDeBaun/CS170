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

//includes---------------------------------
#include <iostream>
#include <fstream>
#include <vector>

#include "DataParser.h"
#include "DataObject.h"
#include "NearestNeighborClassifier.h"
#include "Validator.h"
#include "Search.h"

//using------------------------------------
using std::vector;
using std::cout;




//MAIN---------------------------------------------------------------------------
//-------------------------------------------------------------------------------
int main()
{
	//convert sample data set to numeric values-------

	//small data set----------------------------------
	cout << "Small Dataset: ";
	vector <double> dataVector;

	//prepare data object (holds vector and normalization routine)
	DataObject *data;
	data = new DataObject(dataVector);

	//data parser-------------------------------------
	DataParser conversion; //data conversion object parses ascii-text datafile and stores its normalized dataset
	conversion.parseDataFile("data/cs_170_small80.txt", data, true); //parameters: filename, vector, debug = false
	conversion.printTable(data); //debug -> verify: normalized

	//search------------------------------------------
	Search searchFeatures(data);
	searchFeatures.findBestFeatures();



	//large data set----------------------------------
	cout<< "\n" << "Large Dataset: ";
	vector <double> largeDataVector;
	DataObject *largeData;
	largeData = new DataObject(largeDataVector);
	//conversion.parseDataFile("data/cs_170_large80.txt", largeData); //parameters: filename, vector, debug = false



	//cleanup-----------------------------------------
	delete data;
	delete largeData;
	//delete classifier;

	return 0;

}//end main-------------------------------------------///