
#include <algorithm>
#include <stdlib.h> 
#include <cstring>
#include <memory>
#include <unordered_map>
#include <unordered_set>


bool is_sliding_With_WindowDoubleValue_hashmap(int* arr, int size, int k)  //  1,2,1,4,5 k=3
{   

    if (k < 2 || size < 2)
        return false;

    if (k > size) 
        k = size;

    std::unordered_map<int, int> freq;      //hashmap

    for (int i = 0; i < k; ++i)
    {
        //if(freq.count(arr[i])) return false;
        //freq.insert(arr[i], 0);
        if(++freq[arr[i]] > 1)
            return false;
    }

    for (int i = k; i < size; ++i)
    {
        int start = i - k - 1;
        if (--freq[arr[start+1]] == 0)
            freq.erase(arr[start+1]);
        int end = i + k - 1;
        if(++freq[arr[end]] > 1) 
            return false;
    }

    return true;
}







bool is_sliding_NO_WindowDoubleValue(int* arr, int size, int k)    //  1,2,1,4,5 k=3
{   // ~O(n^2) O(nk) פחות

    if (k < 2 || size < 2)
        return false;

    if (k > size) 
        k = size;
    
    auto copy = std::make_unique<int[]>(k);// int* copy = (int*)malloc(k * sizeof(int)); if (!copy)  return false;

    for (int i = 0; i < size; ++i)
    {

        memcpy(copy.get(), arr + i, (size_t)k * sizeof(int));
        std::sort(copy.get(), copy.get() + k); //prefer quick sort
        for(int j = 1; j < k; ++j)
        {
            if(copy[j-1]==copy[j])
            {
                //free(copy);
                return true;
            }
        }
        
    }
    //free(copy);
    return true;
}





#include <unordered_set>

bool is_sliding_WindowNoDuplicates_set(const int* arr, int size, int k)
{       // O(n log k)

/*  מחזיר true אם אף חלון באורך k לא מכיל כפילויות              *
 *  זמן   O(n)   (O(1) אמורטי להוספה/מחיקה ב-unordered_set)      *
 *  זיכרון O(k)                                                 */
    if (k < 2 || size < 2)
        return false;                    // אין מה לבדוק
    if (k > size)
        k = size;                        // חלון יחיד באורך size
    std::unordered_set<int> window;      // ערכים ייחודיים בחלון
    /* --- חלון ראשון -------------------------------------------------- */
    for (int i = 0; i < k; ++i)
        if (!window.insert(arr[i]).second)   // insertion failed → כפילות
            return false;

    /* --- הזזת חלון צעד-אחד ------------------------------------------ */
    for (int i = k; i < size; ++i)
    {
        int outgoing = arr[i - k];       // האיבר שיוצא
        window.erase(outgoing);

        int incoming = arr[i];           // האיבר שנכנס
        if (!window.insert(incoming).second) // כבר קיים → כפילות
            return false;
    }

    return true;                         // לא נמצאו כפילויות בשום חלון
}


