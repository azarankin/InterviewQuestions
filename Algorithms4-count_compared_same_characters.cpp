#include"pch"

string compressString(const string& input) {
    //string result = "";
    stringstream result;

    if (input.length() < 1) return result.str();

    int count = 1;
    for (size_t i = 1; i < input.length(); i++) {
        if (input[i - 1] == input[i]) {
            count++;
            continue;
        }
        result << to_string(count) << input[i - 1];
        count = 1;
    }
    // == input.length()
    result << to_string(count) << input[input.length()];

    return result.str();
}

int main_compressString() {
    string input = "aabbccdaa";
    string compressed = compressString(input);

    cout << "Compressed result: " << compressed << endl;
    // Compressed result: 2a2b2c1d2a

    return 0;
}
