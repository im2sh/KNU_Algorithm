//
// Created by 이석환 on 2023/05/29.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, W, maxProfit;
vector<int> w, p;

typedef struct item {
    int weight, profit, profitPerUnit;
} ITEM;

bool compareProfitPerUnit(ITEM a, ITEM b) {
    return a.profitPerUnit > b.profitPerUnit;
}

typedef struct node *NODE;
typedef struct node {
    int level;
    int weight;
    int profit;
    float bound;
} nodetype;

struct COMPARE {
    bool operator()(NODE u, NODE v) {
        if (u->bound < v->bound) return true;
        return false;
    }
};

typedef priority_queue<NODE, vector<NODE>, COMPARE> NODEPQ;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

float bound(NODE T) {
    if (T->weight >= W) return 0;
    else {
        float res = T->profit;
        int i = T->level + 1;
        int totWeight = T->weight;
        while (i <= N && totWeight + w[i] <= W) {
            totWeight += w[i];
            res += p[i];
            i++;
        }
        int j = i;
        if (j <= N) res += (W - totWeight) * ((float) p[j] / w[j]);
        return res;
    }
}

NODE create(int level, int weight, int profit) {
    NODE T = (NODE) malloc(sizeof(nodetype));
    T->level = level;
    T->weight = weight;
    T->profit = profit;
    T->bound = bound(T);
    return T;
}

void printNode(NODE T) {
    cout << T->level << " " << T->weight << " " << T->profit << " " << T->bound << endl;
}

void knapsack() {
    NODEPQ PQ;
    NODE u, v;
    maxProfit = 0;

    PQ.push(create(0, 0, 0));
    printNode(PQ.top());

    while (!PQ.empty()) {
        v = PQ.top();
        PQ.pop();
        if (v->bound > maxProfit) {
            u = create(v->level + 1, v->weight + w[v->level + 1], v->profit + p[v->level + 1]);
            printNode(u);
            if (u->weight <= W && u->profit > maxProfit) maxProfit = u->profit;
            if (u->bound > maxProfit) PQ.push(u);
            u = create(v->level + 1, v->weight, v->profit);
            printNode(u);
            if (u->bound > maxProfit) PQ.push(u);
        }
    }
}

void solve() {
    cin >> N >> W;
    vector<item> I(N);
    w.assign(N + 1, 0);
    p.assign(N + 1, 0);

    for (int i = 0; i < N; i++) cin >> I[i].weight;
    for (int i = 0; i < N; i++) {
        cin >> I[i].profit;
        I[i].profitPerUnit = I[i].profit / I[i].weight;
    }
    sort(I.begin(), I.end(), compareProfitPerUnit);
    for (int i = 0; i < N; i++) {
        w[i + 1] = I[i].weight;
        p[i + 1] = I[i].profit;
    }

    knapsack();
    cout << maxProfit << "\n";
}

int main() {
    FastIO();
    solve();
    return 0;
}
