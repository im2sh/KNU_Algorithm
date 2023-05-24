#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct item {
    int weight, profit, profitPerUnit;
} ITEM;

bool COMPARE(ITEM a, ITEM b) {
    return a.profitPerUnit > b.profitPerUnit;
}

int n, W, maxprofit;
vector<int> p, w;
vector<bool> include, bestset;
float bound = 0;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool promising(int i, int profit, int weight) {
    int j, k, totweight;

    if (weight >= W) {
        cout << i << " " << weight << " " << profit << " " << bound << " " << maxprofit << endl;
        return false;
    } else {
        j = i + 1;
        bound = profit;
        totweight = weight;
        while (j <= n && totweight + w[j] <= W) {
            totweight += w[j];
            bound += p[j];
            j++;
        }
        k = j;
        if (k <= n) bound += (W - totweight) * (p[k] / w[k]);

        cout << i << " " << weight << " " << profit << " " << bound << " " << maxprofit << endl;

        return bound > maxprofit;
    }
}

void knapsack(int i, int profit, int weight) {
    if (weight <= W && profit > maxprofit) {
        maxprofit = profit;
        copy(include.begin(), include.end(), bestset.begin());
    }

    if (promising(i, profit, weight)) {
        include[i + 1] = true;
        knapsack(i + 1, profit + p[i + 1], weight + w[i + 1]);
        include[i + 1] = false;
        knapsack(i + 1, profit, weight);
    }
}

void solve() {
    cin >> n >> W;

    vector<ITEM> I(n);
    w.assign(n + 1, 0);
    p.assign(n + 1, 0);
    include.assign(n + 1, false);
    bestset.assign(n + 1, false);

    for (int i = 0; i < n; i++) cin >> I[i].weight;
    for (int i = 0; i < n; i++) {
        cin >> I[i].profit;
        I[i].profitPerUnit = I[i].profit / I[i].weight;
    }
    sort(I.begin(), I.end(), COMPARE);
    for (int i = 0; i < n; i++) {
        w[i + 1] = I[i].weight;
        p[i + 1] = I[i].profit;
    }

    knapsack(0, 0, 0);
    cout << maxprofit << endl;
    for (int i = 1; i < n + 1; i++)
        if (bestset[i]) cout << w[i] << " " << p[i] << endl;
}

int main() {
    FastIO();
    solve();
    return 0;
}
