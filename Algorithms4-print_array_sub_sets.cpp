
#include"pch"





void printArraySubsets(const vector<char>& arr) {
    int n = arr.size();
    int totalSubsets = pow(2, n);

    for (int subvariant = 1; subvariant < totalSubsets; subvariant++) {
       string subset = "";
       for (int variant = 0; variant < n; variant++) {
           if (subvariant & (1 << variant)) { 
               subset += arr[variant];
           }
       }
       cout << subset << endl;
    }
    //subvariant            00001  00010   00011   00100   00101   00110
    // (1 << variant)       00000  00001   00010   00100   01000   10000
}


int main_printArraySubsets() {
    vector<char> arr;
    int size = 5; // abcde
    //cout << "Enter the number of elements: ";
    //cin >> size;

    cout << "Enter the characters: ";
    for (int i = 0; i < size; i++) {
        char ch = (char)((int)'a' + i);
        arr.push_back(ch);
    }

    cout << "Subsets:" << endl;
    printArraySubsets(arr);

    return 0;
}
