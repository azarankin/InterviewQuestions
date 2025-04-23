#include <iostream>
#include <vector>

std::vector<int> fibonacci(int N) {
    std::vector<int> fib;
    if (N <= 0) return fib;
    fib.push_back(0);
    if (N == 1) return fib;
    fib.push_back(1);
    //
    for (int i = 2; i < N; ++i) {
        fib.push_back(fib[i - 1] + fib[i - 2]);
    }

    return fib;//fib[i - 1] + fib[i - 2]
}

int fib2(int n) {
    if (n <= 1)
        return n;

    int prev = 0, curr = 1;
    for (int i = 2; i <= n; ++i) {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }

    return curr;
}

int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int N = 10;
    std::vector<int> result = fibonacci(N);

    std::cout << "Fibonacci sequence up to N=" << N << ":\n";
    for (int num : result) {
        std::cout << num << " ";
    }

    return 0;
}