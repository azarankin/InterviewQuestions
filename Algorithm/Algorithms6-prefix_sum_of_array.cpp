#include <vector>
#include <stdexcept>

class PrefixSumArra
{
private:
    int size=0;
    std::vector<int> previuse_array;
public:
    PrefixSumArra(const std::vector<int>& array):
        size{array.size()}
    {
        previuse_array.reserve(size);
        previuse_array[0] = array[0];

        for(int i = 1; i < size; ++i)
        {
            previuse_array[i] = previuse_array[i - 1] + array[i];
        }

    }

    int prefix_sum_array(int day_to_sum)
    {
        if (day_to_sum >= size)
            throw std::out_of_range("Index out of range in getPrefix");
        return previuse_array[day_to_sum];
    }


    // Query sum on interval [l..r] in O(1)
    int rangeSum(int l, int r) {
        if (l < 0)
            l = 0;
        if (r >= size)
            r = size - 1;
        if (l == 0) 
            return previuse_array[r];
        else 
            return previuse_array[r] - previuse_array[l - 1];
    }
};


