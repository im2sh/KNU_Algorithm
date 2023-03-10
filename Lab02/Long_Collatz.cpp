#include <iostream>

using namespace std;

int find_long(int n) {
    int cnt = 0;
    if (n == 1)
        cnt = 1;
    while (n != 1) {
        cnt++;
        if (n % 2 == 0)
            n /= 2;
        else
            n = (n * 3) + 1;
    }
    return cnt;
}

void print_collatz(int n) {
    while (n != 1) {
        cout << n << " ";
        if (n % 2 == 0)
            n /= 2;
        else
            n = (n * 3) + 1;
    }
    cout << n << "\n";
}

int main(void) {
    int n, m;
    int max_num = 0;
    int temp;
    int check;
    cin >> n >> m;
    for (int i = n; i < m; i++) {
        temp = find_long(i);
        if (max_num < temp) {
            check = i;
            max_num = temp;
        }
    }
    cout << check << " " << max_num << "\n";
    print_collatz(check);

    return 0;
}
