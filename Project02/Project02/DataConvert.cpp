#include "DataConvert.h"


//openFile (tests for valid file)---------------------
bool DataConvert::openFile(fstream &file, const char *name)
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
void DataConvert::convertFile(fstream &file, const char *name, vector<double> &numbers, bool debug)
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
				if (debug)
				{
					cout << std::fixed;
					cout << std::setprecision(9);
					cout << number << std::endl; //debug output as double
				}
				

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





