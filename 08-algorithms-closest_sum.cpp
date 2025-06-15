//#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

pair<int, int> closestSum(vector<int> arr, int x) {
    // your code goes here
    if (arr.size() < 2) return { -1, -1 };

    int s = 0;
    int e = arr.size() - 1;
    pair<int, int> closesum = {arr[s], arr[e]};
    int diff = numeric_limits<int>::max();
    while (s < e)
    {
        //int mid = (s+e) /2;
        int sum = arr[s] + arr[e];
        int currentDiff = abs(x - sum);
        //diff = std::min(currentDiff, diff);
        if (currentDiff < diff) {
            diff = currentDiff;
            closesum = { arr[s], arr[e] };
        }


        if (sum == x) return { arr[s], arr[e] };
        else if (sum < x) ++s;
        else --e;

        
    }
    return closesum;
}