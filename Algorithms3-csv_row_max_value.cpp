#include"pch.h"

/*
* S is the CSV
* C is the header column name
*/
int csvRowMaxValue(string& S, string& C)
{
	int maxValue = INT_MIN;
	int c = -1;	//index number

	istringstream ss(S);

	//First line of the csv file
	vector<string> headers;
	string line;
	string cell;
	getline(ss, line); //\n
	istringstream row(line);
	int i = 0;
	while (getline(row, cell, ','))
	{
		headers.push_back(cell);
		if (C == cell)
		{
			c = i;
		}
		++i;
	}
	if (c == -1) return -1;

	//Find the maxValue
	while (getline(ss, line))
	{
		istringstream row(line);
		int i = 0;
		while (getline(row, cell, ','))
		{
			if (c == i)
			{
				maxValue = max(maxValue, stoi(cell));
			}
			++i;
		}
	}

	return maxValue;
}