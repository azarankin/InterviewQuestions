#include <string>

#include <algorithm>

#include <sstream>

std::string reverseString(const std::string& s) {
    std::string result = s;
    std::reverse(result.begin(), result.end());
    return result;
}



std::string reverseString2(const std::string& s) {
    std::string result = s;
    int left = 0, right = result.size() - 1;

    while (left < right) {
        std::swap(result[left], result[right]);
        ++left;
        --right;
    }

    return result;
}


std::string reverseWords(const std::string& s) {
    std::istringstream ss(s);
    std::string word/*, result*/;
    std::stringstream result;
    while (ss >> word) {
        //word.reserve();
        std::reverse(word.begin(), word.end());
        result << word;
        //if (!result.empty()) result += " ";
        //result += word;
    }
    return result.str();
}
