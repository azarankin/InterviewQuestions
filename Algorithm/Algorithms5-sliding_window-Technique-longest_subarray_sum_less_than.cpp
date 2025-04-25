#include <iostream>
#include <vector>
#include <algorithm>   // std::max

/*  החזר את אורך תת-המערך הרצוף הארוך ביותר שסכומו < S.
 *  מניח שהערכים אינם שליליים; אם קיימים שליליים דרוש אלגוריתם שונה.
 *  זמן  O(n)   |   זיכרון  O(1)
 */
int longestSubarraySumLessThan(const std::vector<int>& a, int S)
{
    int n = (int)a.size();
    if (n == 0 || S <= 0) return 0;

    int left = 0;           // גבול שמאלי של החלון (כלול)
    long long cur = 0;      // סכום החלון [left, right]
    int best = 0;

    for (int right = 0; right < n; ++right)
    {
        cur += a[right];                // מרחיבים את החלון ימינה

        /* מצמצמים משמאל עד שהסכום שוב < S  */
        while (cur >= S && left <= right)
        {
            cur -= a[left];
            ++left;
        }

        /* כעת cur < S  →  החלון [left, right] תקף */
        best = std::max(best, right - left + 1);
    }
    return best;
}

/* ———  דוגמת שימוש  ——— */
int main()
{
    std::vector<int> a = {4, 5, 2, 0, 1, 8, 12, 3, 6, 9};
    int S = 15;

    std::cout << "longest length = "
              << longestSubarraySumLessThan(a, S) << '\n';
    return 0;
}
