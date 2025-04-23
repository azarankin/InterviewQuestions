std::unordered_map<char, int> countChars(const std::string& s) {
    std::unordered_map<char, int> freq;
    for (char c : s)
        freq[c]++;
    return freq;
}
