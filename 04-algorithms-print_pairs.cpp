#include<iostream>
#include<algorithm>
using namespace std;

//Problem : Print all subarrays of a given array
void printAllPairs(int arr[], int n) {
	//All possible pairs
	for (int i = 0;i < n;i++) {
		for (int j = i + 1; j < n;j++) {

			cout << arr[i] << "," << arr[j] << '\n';
		}

	}
}


	//{10, 20, 30, 40, 50}
	// i|             j|
void printSubarrays(int arr[], int n) {
	for (int i = 0;i < n;i++) {
		for (int j = i; j < n;j++) {
			for (int k = i;k <= j;k++) {
				cout << arr[k] << ",";
			}
			cout << '\n';
		}
		//cout << '\n';
	}

}

//O(n^3)
//{10, 20, 30, 40, 50}
// i|             j|
int printSubarrays_largest_sum(int arr[], int n) {
	int largest_sum = 0;

	for (int i = 0;i < n;i++) {
		for (int j = i; j < n;j++) {
			int subarraySum = 0;
			for (int k = i;k <= j;k++) {
				subarraySum += arr[k];
			}
			//put a check is subarraySum > largest_sum
			largest_sum = max(largest_sum, subarraySum);
		}
	}

	return largest_sum;
}







//O(n^2)
//{10, 20, 30, 40, 50}
// i|             j|
int printSubarrays_prefix_sum_prefix_array(int arr[], int n) {
	int* prefix_j = new int[n];
	fill(prefix_j, prefix_j + n, 0);
	prefix_j[0] = arr[0];
	/*
	prefix[0] = 1
	prefix[1] = 1 + 2 = 3
	prefix[2] = 1 + 2 + (-3) = 0
	prefix[3] = 1 + 2 + (-3) + 4 = 4
	prefix[4] = 1 + 2 + (-3) + 4 + 5 = 9
	+*/
	for (int j = 1;j < n; ++j)
	{
		prefix_j[j] = prefix_j[j - 1] + arr[j];
	}

	int largest_sum = 0;

	for (int i = 0;i < n;i++) {
		for (int j = i; j < n;j++) {
			int subarraySum;
			if (i > 0) subarraySum = prefix_j[j] - prefix_j[i - 1];
			else /*(i == 0)*/ subarraySum = prefix_j[j] - 0;

	/*		for (int k = i;k <= j;k++) {
				subarraySum += arr[k];
			}*/
			//put a check is subarraySum > largest_sum
			largest_sum = max(largest_sum, subarraySum);
		}
	}
	
	delete[] prefix_j;
	return largest_sum;
}



// Print the sum of each subarray & find out the largest sum


int main() {
	//Array Containing 
	int arr[] = { -2,3,4,5,-12,6,2,3 };
	int n = sizeof(arr) / sizeof(int);

	printSubarrays(arr, n);



	return 0;
}