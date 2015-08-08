#ifndef CSVWRITER_H
#define CSVWRITER_H

#include <string>
#include "Vector.h"
using namespace std;

class CsvWriter
{
private:
	Vector<string> _lines;
	int _current_line;

public:
	CsvWriter()
	{
		_current_line = 0;
		_lines.addElement("");
	}
	
	//adds a new cell to the current row
	void addText(string text)
	{
		string &current_line = _lines[_current_line];
		
		//create new column if necessary
		if(current_line.length() > 0)
		{
			current_line += ",";
		}

		current_line += "\"" + text + "\"";
	}

	//Moves CsvWriter to the next line in
	//the CSV file
	void nextLine()
	{
		_lines.addElement("\n");
        _current_line++;
		_lines.addElement("");
		_current_line++;
	}

	//Converts the class into a string-based
	//CSV file
	string toString()
	{
		string output = "";
		for(int i = 0; i < _lines.getSize(); i++)
		{
			output += _lines[i];
		}
		return output;
	}
};

#endif