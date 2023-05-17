#include <iostream>
#include <vector>

using namespace std;
#define lli long long int
#define MAX 100000

int n;
int cnt = 0;
lli ans = 0xffffffffffffffff;
int mem[MAX];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    cin >> n;
}

bool promising(int y, int x) {
    for (int i = 1; i < y; i++)
        if (abs(mem[i] - x) == abs(i - y) || mem[i] == x)
            return false;
    return true;
}

lli toInt() {
    lli rst = 0;
    for (lli i = n, mult = 1; i >= 1; i--) {
        int t = mem[i];
        do {
            rst += (t % 10) * mult;
            t /= 10;
            mult *= 10;
        } while (t != 0);
    }
    return rst;
}


void solve(int y) {
    if (y > n) {
        cnt++;
        lli pathInt = toInt();
        if (ans < pathInt) ans = pathInt;
    } else {
        for (int i = 1; i <= n; i++) {
            if (promising(y, i) == true) {
                mem[y] = i;
                solve(y + 1);
                mem[y] = 0;
            }
        }
    }
}

int main() {
    FastIO();
    init();
    solve(1);

    cout << cnt << "\n" << ans;

    return 0;
}