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
    std::stringstream ss(s);
    std::string word, result;
    while (ss >> word) {
        std::reverse(word.begin(), word.end());
        if (!result.empty()) result += " ";
        result += word;
    }
    return result;
}
