#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {

        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr) {
    int n = arr.size();

    for (int curr_size = 1; curr_size < n; curr_size *= 2) {
        for (int left = 0; left < n - 1; left += 2 * curr_size) {
            int mid = min(left + curr_size - 1, n - 1);
            int right = min(left + 2 * curr_size - 1, n - 1);
            merge(arr, left, mid, right);
        }
    }
}

int main_mergeSort() {
    vector<int> arr = { 38, 27, 43, 3, 9, 82, 10 };
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    mergeSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
