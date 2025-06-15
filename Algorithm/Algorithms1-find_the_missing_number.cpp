#include "pch"

int findMissingNumber(const vector<int>& numbers, int n) {
    // Calculate the expected sum of numbers from 1 to N
    int expectedSum = n * (n + 1) / 2;

    // Calculate the sum of numbers in the array
    int actualSum = 0;
    for (int num : numbers)
    {
        actualSum += num;
    }


    return expectedSum - actualSum;
}

int main34324() {

    //std::sort(, );
    // Example usage
    vector<int> numbers = { 1, 2, 3, 5 }; // The missing number is 4
    int n = 5;

    int missingNumber = findMissingNumber(numbers, n);
    cout << "The missing number is: " << missingNumber << endl;

    return 0;
}

int findMissingNumber2(const vector<int>& numbers) {
    for (size_t i = 0; i < numbers.size() - 1; ++i) {
        // If the difference between two consecutive elements is not 1, 
        // the missing number is between them
        if (numbers[i + 1] != numbers[i] + 1) {
            return numbers[i] + 1;
        }
    }
    // If no missing number is found, return an invalid value (e.g., -1)
    return -1;
}
