//
// Created by 이석환 on 2023/05/29.
//
#include <iostream>
#include <vector>
#include <cmath>

#define INF 9999
using namespace std;

int N, M, minLength = INF;
typedef vector<vector<int>> MAT;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int diff(int A, int j) {
    return (A & ~(1 << (j - 2)));
}

bool isIn(int i, int A) {
    return (A & (1 << (i - 2))) != 0;
}

int minimum(int i, int &minJ, int A, MAT &W, MAT &D) {
    int minV = INF, value;
    for (int j = 2; j < N + 1; j++) {
        if (!isIn(j, A)) continue;
        int value = W[i][j] + D[j][diff(A, j)];
        if (minV > value) {
            minV = value;
            minJ = j;
        }
    }
    return minV;
}

int count(int A) {
    int cnt = 0;
    for (; A != 0; A >>= 1)
        if (A & 1) cnt++;
    return cnt;
}

void travel(MAT W, MAT &D, MAT &P) {
    int subsetSize = pow(2, N - 1);
    for (int i = 2; i < N + 1; i++) D[i][0] = W[i][1];

    int i, j, A;
    for (int k = 1; k < N - 1; k++) {
        for (A = 0; A < subsetSize; A++) {
            if (count(A) != k) continue;
            for (i = 2; i < N + 1; i++) {
                if (isIn(i, A)) continue;
                D[i][A] = minimum(i, j, A, W, D);
                P[i][A] = j;
            }
        }
    }

    A = subsetSize - 1;
    D[1][A] = minimum(1, j, A, W, D);
    P[1][A] = j;
    minLength = D[1][A];
}

void tour(int x, int y, MAT &P) {
    int k = P[x][y];
    if (y == 0) cout << " 1" << endl;
    else {
        cout << " " << k;
        tour(k, diff(y, k), P);
    }
}

void solve() {
    cin >> N >> M;
    int subsetSize = pow(2, N - 1);
    MAT W(N + 1, vector<int>(N + 1, INF));
    MAT D(N + 1, vector<int>(subsetSize, INF));
    MAT P(N + 1, vector<int>(subsetSize));

    for (int i = 0; i < M; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        W[x][y] = w;
    }

    travel(W, D, P);
    cout << minLength << endl << 1;
    tour(1, subsetSize - 1, P);
    for (int i = 1; i < N + 1; i++) {
        for (int j = 0; j < subsetSize; j++)
            if (D[i][j] != INF) cout << i << " " << j << " " << D[i][j] << endl;
    }
}

int main() {
    FastIO();
    solve();
    return 0;
}
