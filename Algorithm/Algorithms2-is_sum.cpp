#include"pch.h"


/*
for a sorted array find if sum of t between 2 elements is possible
O(n)
*/
bool isSum(vector<int>& arr, int t)
{
    sort(arr.begin(), arr.end());
    int start = 0;
    int end = arr.size() - 1;

    while (start < end)
    {
        int sum = arr[start] + arr[end];
        if (sum < t) ++start;
        else if (sum > t) --start;
        else return true;
    }
    return false;
}
