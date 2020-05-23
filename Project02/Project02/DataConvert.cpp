#include "DataConvert.h"


//openFile (tests for valid file)---------------------
bool DataConvert::openFile(const char *name)
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
void DataConvert::convertFile(const char *name, vector<double> &numbers, bool debug)
{
	if (openFile(name))//test for valid file -> begin conversion if so
	{
		string word; //accumulates collection of characters -> represents parsed data field
		char ch; //individual characters from text file
		bool newWord = false; //track if on new data field
		double number; //temporarily holds converted parsed value

		file.get(ch);//get first char from text file

		while (!file.eof())
		{
			if (ch != ' ' && ch != 10)//if not space or newline
			{
				word.push_back(ch); //add the char to word
				newWord = true;//on a new word
			}
			else if ((ch == ' ' || ch == 10) && newWord) //if space or newline char and its a new word
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

			file.get(ch); //get next char from text file

		}//end while---//

		file.close(); //close the file
	}
	else
	{
		cout << "Error reading file \n";
	}

}//end convertFile---//





