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

//using------------------------------------
using std::vector;
using std::cout;




//MAIN---------------------------------------------------------------------------
//-------------------------------------------------------------------------------
int main()
{
	//convert sample data set to numeric values-------
	DataParser conversion; //data conversion object parses ascii-text datafile and stores its normalized dataset

	//small data set----------------------------------
	cout << "Small Dataset: ";
	vector <double> smallDataVector;
	DataObject *smallData;
	smallData = new DataObject(smallDataVector);
	conversion.parseDataFile("data/cs_170_small80.txt", smallData, true); //parameters: filename, vector, debug = false
	conversion.printTable(smallData); //debug -> verify: normalized

	//classifier initialization-----------------------
	//NearestNeighborClassifier classifier(smallData);
	NearestNeighborClassifier *classifier;
	classifier = new NearestNeighborClassifier(smallData);

	//vector<bool> key(11, true);//test key
	//vector<bool> key{false,false, true, false, true, false, false, false, false, false, false };//test key
	//cout << "Nearest class is: " << classifier.classifier(37, key);//test case -> manual instance selection

	Validator validatator(classifier);
	//validatator.validate();

	//large data set----------------------------------
	cout<< "\n" << "Large Dataset: ";
	vector <double> largeDataVector;
	DataObject *largeData;
	largeData = new DataObject(largeDataVector);
	conversion.parseDataFile("data/cs_170_large80.txt", largeData); //parameters: filename, vector, debug = false



	//cleanup-----------------------------------------
	delete smallData;
	delete largeData;
	delete classifier;

	return 0;

}//end main-------------------------------------------///