#include <iostream>

using namespace std;

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int past2 = 0;
    int past = 1;
    int result = 0;

    for (int i = 2; i <= n; i++) {
        result = past + past2;
        past2 = past;
        past = result % 1000000;

    }
    return result;
}


int main(void) {
    int n;
    cin >> n;
    cout << fib(n);
}