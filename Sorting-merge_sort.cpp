#include"pch"
namespace {


    // O(nlog(n))
    // Merge two sorted subarrays into one sorted array
    void merge(vector<int>& arr, int left, int mid, int right) 
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Temporary arrays
        vector<int> L(n1), R(n2);


        //copy(arr.begin() + left, arr.begin() + left + n1, L.begin());
        //copy(arr.begin() + mid + 1, arr.begin() + mid + n2, R.begin());

        int l = 0, r = 0;

        // Copy data to temp arrays
        while(l < n1)
            L[l++] = arr[left + l];

        while (r < n2)
            R[r++] = arr[mid + 1 + r];
         
        l = r = 0;

        // Merge the temp arrays back into arr[left...right]
        while (l < n1 && r < n2) 
        {
            if (L[l] <= R[r]) 
            {
                arr[left++] = L[l++];
            }
            else 
            {
                arr[left++] = R[r++];
            }
        }

        // Copy remaining elements of L[], if any
        while (l < n1) 
        {
            arr[left++] = L[l++];
        }

        // Copy remaining elements of R[], if any
        while (r < n2) 
        {
            arr[left++] = R[r++];
        }
    }

    // Recursive merge sort function
    void mergeSort(vector<int>& arr, int left, int right) 
    {
        if (left >= right)
            return;
        //if (left < right)
        //{
        int mid = left + (right - left) / 2;

        // Sort first and second halves recursively
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
        //}
    }

    void mergeSort(vector<int>& arr)
    {
        mergeSort(arr, 0, arr.size() - 1);
    }


    // Utility function to print the array
    void printArray(const vector<int>& arr)
    {

        for (int num : arr)
        {
            cout << num << " ";
        }
        cout << endl;
    }

};
int main() {
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };

    cout << "Original array: ";
    printArray(arr);

    mergeSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
