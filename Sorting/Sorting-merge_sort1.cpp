#include <iostream>
#include <vector>
using namespace std;
/*
    recursion returned to array nums1
    parameters nums1, m is given size of nums1
    parameters nums2, n is total size of nums2
    nums1 total size n+m
*/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    int p1 = m - 1;
    int p2 = n - 1;
    int p = m + n - 1;

    while (p1 >= 0 && p2 >= 0) 
    {
        if (nums1[p1] > nums2[p2]) 
        {
            nums1[p--] = nums1[p1--];
        }
        else 
        {
            nums1[p--] = nums2[p2--];
        }
        //--p;
    }


    while (p1 >= 0)
    {
        nums1[p--] = nums1[p1--];
    }

    while (p2 >= 0) 
    {
        nums1[p--] = nums2[p2--];
    }
}


int main() 
{
    vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
    vector<int> nums2 = { 2, 5, 6 };

    merge(nums1, 3, nums2, 3);

    for (int num : nums1) 
    {
        cout << num << " ";
    }
    // Output: 1 2 2 3 5 6
}
