
#include"pch"

void printArraySubsets(const vector<char>& arr) {
    int n = arr.size();
    int totalSubsets = pow(2, n);

    //for (int i = 1; i < totalSubsets; i++) {
    //    string subset = "";
    //    for (int j = 0; j < n; j++) {
    //        if (i & (1 << j)) { 
    //            subset += arr[j];
    //        }
    //    }
    //    cout << subset << endl;
    //}

    for (int i = 1; i < totalSubsets; i++) {
        string subset = "";
        int num = i;
        for (int j = 0; num > 0; j++, num /= 2) { // Extract subset without bitwise shift
            if (num % 2 == 1) subset += arr[j]; // Check if current bit is set
        }
        cout << subset << endl;
    }
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
