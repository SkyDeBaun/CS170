//CS170 Project02

//includes--------------------------------
#include <iostream>
#include <sstream> //not using
#include <fstream>
#include <vector>
#include <string>
#include <iomanip> //set precision (debug output)

//using-----------------------------------
using std::istringstream;
using std::vector;
using std::fstream;
using std::string;
using std::ios;
using std::cout;

//function prototypes----------------------
bool openFile(fstream &file, const char *name);
void convertFile(fstream &file, const char *name, vector<double> &numbers);



//MAIN------------------------------------------------
//----------------------------------------------------
int main()
{
	//convert sample data set to numeric values-------
	vector <double> dataTest;
	fstream file;
	convertFile(file, "cs_170_small80.txt", dataTest);

	
	return 0;

}//end main-------------------------------------------///


//openFile (tests for valid file)---------------------
bool openFile(fstream &file, const char *name)
{
	bool status;

	file.open(name, ios::in);
	if (file.fail())
	{
		status = false;
	}
	else
	{
		status = true;
	}

	return status;
}//end readFile---//


//convertFile (converts to doubles, store in vector)-
void convertFile(fstream &file, const char *name, vector<double> &numbers)
{
	if (openFile(file, name))
	{
		string word;
		char ch;
		bool newWord = false;
		double number;

		file.get(ch);//get first char from text file

		while (!file.eof())
		{
			if (ch != ' ' && ch != 10)//if not blank or newline
			{
				word.push_back(ch);
				newWord = true;//on a new word
			}
			else if ((ch == ' ' || ch == 10) && newWord)
			{
				number = std::stod(word);
				numbers.push_back(number); //store in vector of doubles

				//debug (verify output)-----------------------
				//cout << std::fixed;
				//cout << std::setprecision(9);
				//cout << number << std::endl; //debug output as double

				word.clear(); //clear word for next 
				newWord = false;// ready for next new word
			}

			file.get(ch); //get next char from file
		}
	}
	else
	{
		cout << "Error reading file \n";
	}

}//end convertFile---//

