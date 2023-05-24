#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


typedef struct item {
    int weight, profit, profitPerUnit;
} ITEM;

int N, T;

bool COMPARE(ITEM a, ITEM b) {
    return a.profitPerUnit > b.profitPerUnit;
}

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int knapsack(int n, int W, vector<int> w, vector<int> p, map<pair<int, int>, int> &P) {
    if (n == 0 || W <= 0) return 0;
    if (P.count({n, W})) return P[{n, W}];

    int leftV = knapsack(n - 1, W, w, p, P);
    int rightV = knapsack(n - 1, W - w[n - 1], w, p, P);
    P[make_pair(n, W)] = (w[n - 1] > W) ? leftV : max(leftV, p[n - 1] + rightV);
    return P[make_pair(n, W)];
}

void solve() {
    cin >> N;
    vector<int> w(N), p(N), BAG;
    map<pair<int, int>, int> P;

    vector<ITEM> I(N);
    for (int i = 0; i < N; i++) {
        cin >> I[i].weight;
    }
    for (int i = 0; i < N; i++) {
        cin >> I[i].profit;
        I[i].profitPerUnit = I[i].profit / I[i].weight;
    }
    sort(I.begin(), I.end(), COMPARE);

    for (int i = 0; i < N; i++) {
        w[i] = I[i].weight;
        p[i] = I[i].profit;
    }

    cin >> T;
    BAG.assign(T, 0);
    for (int i = 0; i < T; i++) cin >> BAG[i];
    for (int i = 0; i < T; i++) {
        cout << knapsack(N, BAG[i], w, p, P) << endl;
        for (auto &I: P) {
            cout << I.first.first << " " << I.first.second << " " << I.second << endl;
        }
        P.clear();
    }
}

int main() {
    FastIO();
    solve();
    return 0;
}
