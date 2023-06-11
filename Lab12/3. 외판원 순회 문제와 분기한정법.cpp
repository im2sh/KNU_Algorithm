//
// Created by 이석환 on 2023/05/29.
//

#include <iostream>
#include <vector>
#include <queue>

#define INF 999999
using namespace std;

typedef vector<vector<int>> MAT;
typedef vector<int> SET;

typedef struct node NODE;
struct node {
    int level;
    int bound;
    SET path;
};

struct COMPARE {
    bool operator()(NODE u, NODE v) {
        return u.bound > v.bound ? true : false;
    }
};

typedef priority_queue<NODE, vector<NODE>, COMPARE> NODEPQ;

int N;
MAT W;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int length(SET path) {
    int len = 0;
    for (int i = 0; i < path.size() - 1; i++) len += W[path[i]][path[i + 1]];
    return len;
}

bool hasOutGoing(int v, SET path) {
    for (int i = 0; i < path.size() - 1; i++)
        if (path[i] == v) return true;
    return false;
}

bool hasInComing(int v, SET path) {
    for (int i = 1; i < path.size(); i++)
        if (path[i] == v) return true;
    return false;
}

int bound(NODE V) {
    int lower = length(V.path);
    for (int i = 1; i < N + 1; i++) {
        if (hasOutGoing(i, V.path)) continue;
        int minV = INF;
        for (int j = 1; j < N + 1; j++) {
            if (i == j) continue;
            if (hasInComing(j, V.path)) continue;
            if (j == 1 && i == V.path[V.path.size() - 1]) continue;
            if (minV > W[i][j]) minV = W[i][j];
        }
        lower += minV;
    }
    return lower;
}

bool isIn(int v, SET path) {
    for (int i = 0; i < path.size(); i++)
        if (v == path[i]) return true;
    return false;
}

int remainingVertex(SET path) {
    int v = 0;
    for (int i = 0; i < path.size(); i++) v += path[i];
    return N * (N + 1) / 2 - v;
}

void printPath(NODE N) {
    cout << N.level << " ";
    if (N.bound >= INF) cout << "INF";
    else cout << N.bound;

    for (int i = 0; i < N.path.size(); i++) cout << " " << N.path[i];
    cout << endl;
}

void travel(SET &tour, int &minLength) {
    NODEPQ PQ;
    minLength = INF;

    NODE v;
    v.level = 0;
    v.path.push_back(1);
    v.bound = bound(v);

    PQ.push(v);
    printPath(v);

    while (!PQ.empty()) {
        NODE v = PQ.top();
        PQ.pop();
        if (v.bound < minLength) {
            for (int i = 2; i < N + 1; i++) {
                if (isIn(i, v.path)) continue;
                NODE u;
                u.level = v.level + 1;
                u.path.resize(v.path.size());
                copy(v.path.begin(), v.path.end(), u.path.begin());
                u.path.push_back(i);
                u.bound = bound(u);
                if (u.level == N - 2) {
                    u.path.push_back(remainingVertex(u.path));
                    u.path.push_back(1);
                    if (length(u.path) < minLength) {
                        minLength = length(u.path);
                        tour.resize(u.path.size());
                        copy(u.path.begin(), u.path.end(), tour.begin());
                    }
                } else if (u.bound < minLength) PQ.push(u);
                printPath(u);
            }
        }
    }
}

void solve() {
    int M, minLength;
    cin >> N >> M;
    W.assign(N + 1, SET(N + 1, INF));
    for (int i = 1; i < N + 1; i++) W[i][i] = 0;
    for (int i = 0; i < M; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        W[x][y] = w;
    }

    SET tour;
    travel(tour, minLength);
    cout << minLength << endl;

    for (int i = 0; i < tour.size(); i++)
        cout << tour[i] << (i != tour.size() - 1 ? " " : "");
}

int main() {
    FastIO();
    solve();
    return 0;
}

