#include"pch"

int countDifferentBits(int a, int b) {
    int xorResult = a ^ b;  //diifferent bits
    int count = 0;

    // using >> operatr
    while (xorResult) {
        count += (int)(xorResult & 0b1); // do the most right bit is 1
        xorResult >>= 1;
    }

    return count;
}

// Brian Kernighan’s Algorithm
int countDifferentBits2(int a, int b) {
    int xorResult = a ^ b;  //diifferent bits
    int count = 0;

    while (xorResult) {
        xorResult &= (xorResult - 0b1); // remove the right bit from xorResult
        count++;
    }

    return count;
}

int main_countDifferentBits() {
    int a = 7, b = 10;
    cout << countDifferentBits(a, b) << endl;
    return 0;
}