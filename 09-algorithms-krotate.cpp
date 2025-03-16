#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

vector<int> kRotate(vector<int> a, int k)
{
	int n = a.size();
	k = k % n;

	//a		1 2 3 4 5	k=2

	reverse(a.begin(), a.begin() + n - k);
	//	3 2 1 4 5

	reverse(a.begin() + n - k, a.end());
	//	3 2 1 5 4

	reverse(a.begin(), a.end());
	//	4 5 1 2 3

	return a;
}



vector<int> kRotate1(vector<int> a, int k)
{
	int n = a.size();
	k = k % n;

	vector<int> output(n);

	for (int i = n - k; i < n; ++i)
	{
		output.push_back(a[i]);
	}


	for (int i = 0; i < n - k; ++i)
	{
		output.push_back(a[i]);
	}

	return output;
}