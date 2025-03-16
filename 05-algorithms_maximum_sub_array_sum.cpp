#include<iostream>
using namespace std;
//O(n)
int maximum_subarray_sum(int arr[], int n) {

	int currentsum = 0;	//current sum
	int largestSum = 0; //largest sum

	for (int i = 0;i < n;i++) {
		currentsum = max(arr[i], currentsum + arr[i]);
		largestSum = max(largestSum, currentsum);
	}

	return largestSum;
} 


int main_maximum_subarray_sum() {
	//Array Containing 
	int arr[] = { -2,3,4,-1,5,-12,6,1,3 };
	int n = sizeof(arr) / sizeof(int);

	cout << maximum_subarray_sum(arr, n) << endl;

	return 0;
}