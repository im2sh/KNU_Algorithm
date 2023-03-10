#include <iostream>

using namespace std;

int dst_cnt = 0;
int cnt = 0;
int k;

void hanoi(int n, char src, char via, char dst) {
    cnt++;
    if (n == 1) {
        dst_cnt++;
        if (dst_cnt == k)
            printf("%c -> %c\n", src, dst);
    } else {
        hanoi(n - 1, src, dst, via);
        hanoi(1, src, via, dst);
        hanoi(n - 1, via, src, dst);
    }
}

int main() {
    int n;
    cin >> n >> k;
    hanoi(n, 'A', 'B', 'C');
    cout << cnt << "\n";
}