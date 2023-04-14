#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;
typedef long long ll;

int n, k;

bool check[1000000];
vector<int> v;
unordered_map<int, int> pcnt;

ll bin2(ll a, int b) {
    if (!b)
        return 1;

    if (b == 1)
        return a;

    if (b & 1)
        return bin2(a, b - 1) * a % 10007;

    return bin2(a * a % 10007, b / 2);
}

int main() {
    cin >> n >> k;
    check[1] = true;

    for (int i = 2; i <= n; ++i) {
        if (check[i])
            continue;

        v.push_back(i);

        for (int j = i + i; j <= n; j += i)
            check[j] = true;
    }

    for (int j = 0; j < v.size(); ++j)
        for (ll h = v[j]; h <= n; h *= v[j])
            pcnt[v[j]] += n / h - k / h - (n - k) / h;

    ll res = 1;

    for (auto it = pcnt.begin(); it != pcnt.end(); ++it) {
        res *= bin2(it->first, it->second);
        res %= 10007;
    }

    cout << res << "\n";

    return 0;
}
