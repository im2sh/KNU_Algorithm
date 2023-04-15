#include <iostream>

using namespace std;

int fib(int n) {
    int past2 = 1;
    int past = 2;
    int result = 0;

    for (int i = 2; i <= n; i++) {
        result = (past + past2) % 1000;
        past2 = past % 1000;
        past = result % 1000;
        cout << result << "\n";
    }
    return result;
}


int main(void) {
    int n;
    cin >> n;
    cout << fib(n);
}