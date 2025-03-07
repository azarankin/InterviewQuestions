#include <iostream>
#include <vector>



class FastClearArray {
private:
    std::vector<int> arr;
    std::vector<int> versions;
    int version = 0;

public:
    FastClearArray(int size) 
    {
        arr.resize(size, 0);
        versions.resize(size, 0);
    }

    void set(int index, int value) 
    {
        arr[index] = value;
        versions[index] = version; // Mark this index as valid in the current version
    }

    int get(int index) 
    {
        if (versions[index] == version)
            return arr[index];
        return 0; // Treat it as "cleared"
    }

    void clear() 
    {
        ++version; // "Clears" the array logically in O(1)
    }
};


int main_FastClearArray() {
    FastClearArray arr(10);

    arr.set(3, 42);
    std::cout << arr.get(3) << std::endl; // 42

    arr.clear(); // Clear the array in O(1)

    std::cout << arr.get(3) << std::endl; // 0 (The value is earased)

    return 0;
}


// //wrong way
//class FastClearArray1 {
//private:
//    std::vector<int> arr;
//    std::vector<int> repair_arr;
//    bool are_array_repeaired{ false };
//public:
//
//    FastClearArray1(int size) {
//        arr.resize(size, 0);
//        repair_arr.resize(size, 0);
//    }
//    int get(int index)
//    {
//        if (are_array_repeaired)
//            return repair_arr[index];
//        return arr[index];
//    }
//
//
//    void set(int index, int value)
//    {
//        if (are_array_repeaired)
//        {
//            //repair_arr[index] = value;
//            arr.clear();
//        }
//        arr[index] = value;
//        are_array_repeaired = false;
//    }
//
//    void clear()
//    {
//        are_array_repeaired = true;
//    }
//
//};
