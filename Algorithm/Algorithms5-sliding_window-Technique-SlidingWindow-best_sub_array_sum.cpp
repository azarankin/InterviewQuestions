#include <iostream>
#include <vector>
#include <numeric>   // std::accumulate
#include <limits>    // std::numeric_limits

int maxSumSubarrayK(const std::vector<int>& a, int k)
{   // O(n)
    if (k <= 0 || k > (int)a.size())
        return 0;                     // טיפול בקלט לא חוקי

    // חלון ראשון
    int cur  = std::accumulate(a.begin(), a.begin() + k, 0); // + + +
    int best = cur;
    std::cout << "start: " << cur << '\n';

    // הזזת החלון ימינה, r מצביע על האיבר החדש שנכנס
    for (int r = k; r < static_cast<int>(a.size()); ++r)
    {
        cur += a[r];        //std::accumulate(a.begin() + r, a.begin() + r - k, 0); 
        cur -= a[r - k];       // עדכון סכום בזמן O(1)
        best = std::max(best, cur);
        std::cout << cur << ' ';
    }
    std::cout << "\nmax = " << best << '\n';

    return best;
}

int main()
{
    std::vector<int> a = {8, 3, -2, 4, 5, -1, 0, 5, 3, 9, -6};
    int k = 5;
    maxSumSubarrayK(a, k);
    return 0;
}
