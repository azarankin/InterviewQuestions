#include <iostream>

using namespace std;

bool isPerfectSquare(int n) {
    if (n < 0) return false; // negative bumbers cant be in order 2
    int odd = 1;

    while (n > 0) {
        n -= odd;
        odd += 2; // next odd number
    }

    return n == 0;
}

int main_isPerfectSquare() {
    int num = 25;
    bool result = isPerfectSquare(num);
    return 0;
}