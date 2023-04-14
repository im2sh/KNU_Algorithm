#include <iostream>

using namespace std;

int cnt = 0;

int fib(int n) {
    cnt++;
    if (n <= 1) {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

int main(void) {
    int n;
    cin >> n;
    cout << fib(n) << "\n";
    cout << cnt << "\n";
}