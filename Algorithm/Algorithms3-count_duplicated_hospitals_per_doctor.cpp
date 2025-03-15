
#include"pch.h"

/*
	A represents doctors id per A[hospital][day]
*/
int countDuplicatedHospitalsPerDoctor(vector<vector<int>>& A)
{
	int count = 0;
	map<int, set<int>> doctors;

	//Organize the sets of hospitals for each doctor
	for (int hospital = 0; hospital < A.size(); ++hospital)
	{
		for (int day = 0; day < A[day].size(); ++day)
		{
			doctors[A[hospital][day]].insert(hospital);
		}
	}

	//Count doctors with more then one hospital
	for (const auto& doctor : doctors)
	{
		if (doctor.second.size() > 1)
			++count;
	}

	return count;
}
