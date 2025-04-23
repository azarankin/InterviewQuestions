#include <iostream>
#include <map> // או unordered_map
#include <string>

int main() {
    std::map<std::string, int> scores;
    scores["Alice"] = 85;
    scores["Bob"] = 92;
    scores["Charlie"] = 78;

    for (const auto& pair : scores) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }

    return 0;
}