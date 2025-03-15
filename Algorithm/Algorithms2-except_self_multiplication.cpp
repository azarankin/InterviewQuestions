#include"pch.h"


/*
for given array, return an array with multiple elements for each it place except the current place
run in O(n)
*/
vector<int> exceptSelfMultiplication(vector<int>& arr)
{
    //int zeroCount = count(arr.begin(), arr.end(), 0);
    int zeroCount = 0;
    int zeroPlace = -1;
    for (int i = 0; i < arr.size() ; ++i)
    {
        if (arr[i] == 0)
        {
            ++zeroCount;
            zeroPlace = i;
        }
    }

    if (zeroCount >= 2) return vector<int>(arr.size(), 0);

    int arrMultiply = 1;
    for (int el : arr)
    {
        arrMultiply *= el;
    }

    if (zeroCount == 1 /*&& zeroPlace != -1*/)
    {
        vector<int> v(arr.size(), 0);
        //auto zeroPlaceIt = find(arr.begin(), arr.end(), 0);
        //int zeroPlace = distance(arr.begin(), zeroPlaceIt);
        v[zeroPlace] = arrMultiply;
        return v;
    }

    vector<int> v(arr.size(), arrMultiply);
    for (int i = 0; i < arr.size();++i)
    {
        v[i] /= arr[i];
    }

    return v;
}

