#include <iostream>
#include <vector>



class FastClearArray {
private:
    std::vector<int> arr;
    std::vector<int> versions;
    int crurrent_version = 0;

public:
    FastClearArray(int size) 
    {
        arr.resize(size, 0);
        versions.resize(size, 0);
    }

    void set(int index, int value) 
    {
        arr[index] = value;
        versions[index] = crurrent_version; // Mark this index as valid in the current version
    }

    int get(int index) 
    {
        if (versions[index] == crurrent_version)
            return arr[index];
        return 0; // Treat it as "cleared"
    }

    void clear() 
    {
        ++crurrent_version; // "Clears" the array logically in O(1)
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

