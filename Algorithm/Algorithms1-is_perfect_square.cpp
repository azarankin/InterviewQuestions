#include <iostream>

using namespace std;

bool isPerfectSquare(int n) {   //O(sqrt(n))
    if (n < 0) return false; // negative bumbers cant be in order 2
    int odd = 1;

    while (n > 0) {
        n -= odd;
        odd += 2; // next odd number
    }

    return n == 0;
}


bool isPerfectSquare2(int n) {    //O(sqrt(n))
    if (n < 0) return false;
    if (n == 0 || n == 1) return true;

    int odd = 1;
    while( odd*odd < n)
    {
        odd +=2;
    }

    return odd * odd == n;
}


//Two Sum
bool isPerfectSquare3(int n) { //O(log(n))  //better
    if (n < 0) return false;
    int left = 0, right = n;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long sq = (long)mid * mid; // למנוע overflow
        if (sq == n) return true;
        if (sq < n) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

int main_isPerfectSquare() {
    int num = 25;
    bool result = isPerfectSquare(num);
    return 0;
}