#include "HashTable.cpp"
#include <fstream>
#include <iostream>

/*
This class adds character arrays to a hash table,
then searches the hash table for potentially matching 
strings held in a file.

When a string is not found, it's printed to the console.

© 2015 Ray Winkelman
*/

class Controller
{

private:
	string dictionaryfile, file;
	HashTable * hashtable;
	char * temp;

public:
	Controller(int primenumber, string dictionaryfile, string file)
	{
		this->hashtable = new HashTable(primenumber);
		this->dictionaryfile = dictionaryfile;
		this->file = file;
	}

	/* This is the high-level controller */
	void Run(){

		try
		{
			// Filling the table.
			FillTable();

			cout << "Misspelled words are:" << endl;

			// Reading the file. 
			ReadFile();
		}
		catch (...)
		{
			PrintException();
		}

		int getch;
		cin >> getch;
	}

	/* Fills the hash table */
	void FillTable()
	{
		fstream instream;
		instream.open(dictionaryfile);

		while (!instream.eof())
		{
			instream.getline(temp, 512);

			hashtable->Insert(Clean(temp));
		}

		delete temp;
	}

	/* Reads the file */
	void ReadFile()
	{
		fstream instream;
		instream.open(file);

		temp = new char[512];

		while (instream >> temp)
		{
			if (strlen(Clean(temp)) > 0 && !hashtable->Contains(Clean(temp)))
			{
				cout << Clean(temp) << endl;
			}
		}

		delete temp;
	}

	/* Cleans non-word characters from the arrays. */
	char * Clean(char * in){
		char * line = "";
		int i = 0;

		while (in[i])
		{
			if ((in[i] < 123 && in[i] > 96) || (in[i] < 91 && in[i] > 64))
			{
				line = Append(line, tolower(in[i]));
			}

			i++;
		}
		return line;
	}

	/* Helper function to the clean method. */
	char * Append(char * array, char a)
	{
		size_t len = strlen(array);
		char * newarray = new char[len + 2];

		strcpy(newarray, array);
		newarray[len] = a;
		newarray[len + 1] = '\0';

		return newarray;
	}

	/* I hope this never executes */
	void PrintException()
	{
		cout << "Unexpected Exception in Tree." << endl;
	}
};