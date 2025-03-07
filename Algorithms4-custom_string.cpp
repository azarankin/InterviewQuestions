#include"pch"

class CustomString {
private:
    string str; 

public:
    CustomString() : str("") {}

    CustomString(const string& input) : str(input) {}

    int length() const 
    {
        return str.length();
    }

    void toUpperCase() 
    {
        transform(str.begin(), str.end(), str.begin(), ::toupper);
    }

    void toLowerCase() 
    {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
    }

    string reverse() const 
    {
        string reversed = str;
        std::reverse(reversed.begin(), reversed.end());
        return reversed;
    }

    bool equals(const CustomString& other) const 
    {
        return str == other.str;
    }

    CustomString operator+(const CustomString& other) const 
    {
        return CustomString(str + other.str);
    }

    bool operator==(const CustomString& other) const {

        return str == other.str;
    }

    void print() const 
    {
        cout << str << endl;
    }
};

int main_CustomString() {
    CustomString str1("Hello");
    CustomString str2("World");

    CustomString str3 = str1 + str2;

    cout << "Combined string: ";
    str3.print();

    cout << "Reversed string: " << str3.reverse() << endl;

    str3.toUpperCase();
    cout << "Uppercase string: ";
    str3.print();

    cout << "Strings equal: " << (str1 == str2 ? "Yes" : "No") << endl;

    return 0;
}



/*
#include <cstring>

class CustomString {
private:
    char* str;

public:
    CustomString() : str(nullptr) {
        str = new char[1];
        str[0] = '\0';
    }

    CustomString(const char* input) {
        str = new char[strlen(input) + 1];
        strcpy(str, input);
    }

    CustomString(const CustomString& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    ~CustomString() {
        delete[] str;
    }

    int length() const {
        return strlen(str);
    }

    void toUpperCase() {
        for (size_t i = 0; i < strlen(str); ++i) {
            str[i] = toupper(str[i]);
        }
    }

    void toLowerCase() {
        for (size_t i = 0; i < strlen(str); ++i) {
            str[i] = tolower(str[i]);
        }
    }

    CustomString reverse() const {
        int len = strlen(str);
        char* reversed = new char[len + 1];
        for (int i = 0; i < len; ++i) {
            reversed[i] = str[len - i - 1];
        }
        reversed[len] = '\0';
        CustomString reversedString(reversed);
        delete[] reversed;
        return reversedString;
    }

    bool equals(const CustomString& other) const {
        return strcmp(str, other.str) == 0;
    }

    CustomString operator+(const CustomString& other) const {
        int newLength = strlen(str) + strlen(other.str) + 1;
        char* combined = new char[newLength];
        strcpy(combined, str);
        strcat(combined, other.str);
        CustomString result(combined);
        delete[] combined;
        return result;
    }

    bool operator==(const CustomString& other) const {
        return equals(other);
    }

    void print() const {
        cout << str << endl;
    }
};

int main() {
    CustomString str1("Hello");
    CustomString str2("World");

    CustomString str3 = str1 + str2;

    cout << "Combined string: ";
    str3.print();

    cout << "Reversed string: ";
    CustomString reversedStr = str3.reverse();
    reversedStr.print();

    str3.toUpperCase();
    cout << "Uppercase string: ";
    str3.print();

    cout << "Strings equal: " << (str1 == str2 ? "Yes" : "No") << endl;

    return 0;
}

*/