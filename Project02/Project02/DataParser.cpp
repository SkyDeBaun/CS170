#include "DataParser.h"


//openFile (tests for valid file)---------------------
bool DataParser::openFile(const char *name)
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
void DataParser::parseDataFile(const char *name, DataObject *data, bool debug)
{
	if (openFile(name))//test for valid file -> begin conversion routine if so
	{
		string word; //accumulates collection of characters -> represents one parsed data field
		char ch; //individual characters from text file
		bool newWord = false; //track if on new data field
		double number; //temporarily holds converted parsed value
		int columnCounter = 0; //count columns (untill first newline encountered!)
		bool columnsCounted = false;


		file.get(ch);//get first char from text file

		//loop until end of file--------------------------------
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
				data->pushData(number);

				if (!columnsCounted)
				{
					++columnCounter;
				}
								
				if (ch == 10 && !columnsCounted)//count # of columns (allows for auto adjusting)
				{
					columnsCounted = true;
					//cout << "Columns: " << columnCounter << std::endl;
					data->updateCols(columnCounter); //store # columns
				}

				//debug (verify output)-----------------------
				if (debug)//see if debug below for parsed data set (this is element by element only)
				{
					//cout << std::fixed;
					//cout << std::setprecision(8);
					//cout << number << std::endl; //debug output as double
				}

				word.clear(); //clear word for next 
				newWord = false;// ready for next new word
			}

			file.get(ch); //get next char from text file

		}//end while---//
		
		//close the filestream----------------------------------
		file.close(); 		

		//print pre-normalized data-----------------------------
		if (debug)//avoid for very large data sets!
		{
			cout << "The parsed data set (pre-normalized): \n\n"; 
			this->printTable(data);
		}

		//normalize the data set-------------------------------
		this->normalize(data); //can call manually in main for printing before and after verification instead (normalized data IS protected from overwrite)
	}
	else
	{
		cout << "Error reading file \n";
	}

}//end convertFile---//

//verify proper instance (row) capture from parse operation
void DataParser::printTable(DataObject *data)
{
	int size = data->getSize();
	int cols = data->getCols();

	for (size_t i = 0; i < size; ++i)
	{
		cout << std::fixed;
		std::setprecision(10);
		cout << data->getValue(i) << "  ";

		if ((i + 1) % cols == 0)
		{
			cout << "\n";
		}
	}

}//end printTable---//


void DataParser::normalize(DataObject *data)
{
	if (!data->getNormalizedStatus())
	{
		cout <<"\n" <<  "Normalizing the Data Set... \n";
		data->calcAverage();
		data->calcStandardDeviation();
		data->normalize();
	}	

}//end normalize---//

