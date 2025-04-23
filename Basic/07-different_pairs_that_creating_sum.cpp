#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

int countPairsWithSum(const std::vector<int>& nums, int target) {
    //std::unordered_map<int, int> freq;
    std::set<int> freq;
    int count = 0;

    for (int num : nums) {
        int complement = target - num;
        // אם המשלים כבר הופיע בעבר - כל הופעה שלו יוצרת זוג חוקי
        if (freq.count(complement)) {   // freq.find(complement) != freq.end()
            count++;
        }
        // נוסיף את המספר הנוכחי למילון
        freq.insert(num);
        //freq[num]++;    //freg.insert(num)
    }

    return count;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 3};
    int target = 6;

    std::cout << "Number of pairs: " << countPairsWithSum(arr, target) << std::endl;
    return 0;
}
