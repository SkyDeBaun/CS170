//CS170 Project02

//includes--------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//using-----------------------------------
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
	vector <double> dataTest;

	fstream file;
	if (openFile(file, "cs_170_small80.txt"))
	{
		string word;
		char ch;
		int counter = 0;
		bool newWord = false;

		file.get(ch);

		while (!file.eof())
		{
			
			if (ch != ' ' && ch != 10)//if not blank or newline
			{
				word.push_back(ch);
				newWord = true;//on a new word
			}
			else if ((ch == ' '|| ch == 10) && newWord)
			{				
					cout << word << std::endl;
					word.clear();
					newWord = false;// ready for next new word
								
			}

			file.get(ch); //get next char from file
		}
	}
	else
	{
		cout << "Error reading file \n";
	}



	return 0;

}//end main-------------------------------------------///




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


void convertFile(fstream &file, const char *name, vector<double> &numbers)
{
	if (openFile(file, name))
	{
		string word;
		char ch;
		int counter = 0;
		bool newWord = false;

		file.get(ch);

		while (!file.eof())
		{

			if (ch != ' ' && ch != 10)//if not blank or newline
			{
				word.push_back(ch);
				newWord = true;//on a new word
			}
			else if ((ch == ' ' || ch == 10) && newWord)
			{
				cout << word << std::endl;
				word.clear();
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

