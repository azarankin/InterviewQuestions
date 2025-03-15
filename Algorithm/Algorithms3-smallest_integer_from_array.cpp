#include"pch"


int solution(vector<int>& A)
{
	int N = A.size();
	int smallest = 1;
	sort(A.begin(), A.end());
	for (int a : A)
	{
		if (a <= 0) continue;
		if (a == smallest) ++smallest;
		else return smallest;
	}



	return smallest;
}