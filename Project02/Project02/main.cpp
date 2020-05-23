//CS170 Project02 -> Sky DeBaun -> Spring 2020

//includes--------------------------------
#include <iostream>
#include <fstream>
#include <vector>

#include "DataConvert.h"


//using-----------------------------------
using std::istringstream;
using std::vector;
using std::fstream;
using std::string;
using std::ios;
using std::cout;


//function prototypes----------------------



//MAIN------------------------------------------------
//----------------------------------------------------
int main()
{
	DataConvert conversion; //data conversion object converts sample data

	//convert sample data set to numeric values-------
	vector <double> dataTest;
	fstream file;
	conversion.convertFile(file, "cs_170_small80.txt", dataTest, false); //parameters: fstream, filename, vector, debug ouput

	
	return 0;

}//end main-------------------------------------------///


//function definitions--------------------------------