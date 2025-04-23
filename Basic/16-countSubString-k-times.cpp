std::unordered_map<std::string, int> countSubstringsK(const std::string& s, int k) {
    std::unordered_map<std::string, int> freq;
    if (k > s.size()) return freq;

    for (size_t i = 0; i <= s.size() - k; ++i) {
        std::string sub = s.substr(i, k);
        freq[sub]++;
    }
    return freq;
}



std::unordered_map<std::string, int> countAnagramSubstringsK(const std::string& s, int k) {
    std::unordered_map<std::string, int> freq;
    if (k > s.size()) return freq;

    for (size_t i = 0; i <= s.size() - k; ++i) {
        std::string sub = s.substr(i, k);
        std::sort(sub.begin(), sub.end());  // נורמליזציה
        freq[sub]++;
    }
    return freq;
}