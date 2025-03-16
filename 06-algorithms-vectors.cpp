#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> arr = { 1, 2, 10 ,12, 15 };
	arr.size();	//5
	arr.capacity();	//5

	arr.push_back(16);
	arr.size();	//6
	arr.capacity();	//10

	for (int i = 0;i < arr.size();++i) arr[i];


	//Fill the vector
	vector<int> arr2(10, 7); // {7, 7, 7, 7, 7, 7, 7, 7, 7, 7}
	vector<int> visiters(10000, 0);

}