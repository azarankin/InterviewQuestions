#include"pch.h"


/*
	Have seats ABC DEFG HIJ
	N for number of rows 1...N
	S for reserved places inside S string (example "1E 34B")
	Find maximum group of 4 persons, family,  that can set togethe, each group mast contain at least 2 persons in closes places
	(example 2 in BC and 2 in DE if they not reserved)
*/

int countGroupOf4PassengersInThePlaneLine(int N, string& S)
{
	int totalFamilies = 0;

	//Store the reserved places inside datastructure
	map<int, set<char>> reserved;
	istringstream ss(S);
	string seat;
	while (ss >> seat)
	{
		reserved[stoi(seat.substr(0, seat.size() - 1))].insert(seat.back());
	}

	//count how much seat of 4 can we store for totalFamilies
	vector<vector<char>> familySeats = {
		{'D','E','F','G'},	// [0] is the middle posible group
		{'B','C','D','E'},
		{'F','G','H','I'}
	};

	for (int row = 1; row <= N; ++row)
	{
		for (int i = 0; i < familySeats.size(); ++i)
		{
			bool canCount = true;
			for (char seat : familySeats[i])
			{
				if (reserved[row].count(seat))
				{
					canCount = false;
					break;
				}
			}
			if (canCount)
			{
				++totalFamilies;
				if (i == 0) break;	//the middle places of 4 took
			}
		}
	}

	return totalFamilies;
}