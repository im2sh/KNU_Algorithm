#include <iostream>
#include <vector>

using namespace std;

int N, M, T, S;
int cnt;
int circleCnt;

vector<vector<int>> graph;
vector<int> mark;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void make_graph() {
    int imov[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int jmov[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 8; k++) {
                int ni = i + imov[k];
                int nj = j + jmov[k];

                if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
                    graph[i * M + j].push_back(ni * M + nj);
                }
            }
        }
    }
}


void tour(int k, int v) {
    if (k == N * M) {
        mark[v] = k;
        cnt++;
    } else {
        for (int i: graph[v]) {
            if (mark[i] == 0) {
                mark[i] = k + 1;
                tour(k + 1, i);
                mark[i] = 0;
            }
        }
    }
}


void circle(int k, int v) {
    if (k == N * M) {
        for (int i = 0; i < graph[v].size(); i++) {
            if (S == graph[v][i]) {
                mark[v] = k;
                circleCnt++;
            }
        }
    } else {
        for (int i: graph[v]) {
            if (mark[i] == 0) {
                mark[i] = k + 1;
                circle(k + 1, i);
                mark[i] = 0;
            }
        }
    }
}

void solve() {
    cin >> N >> M;

    graph.resize(N * M, vector<int>(0));
    mark.resize(N * M, 0);
    make_graph();

    cin >> T;
    circle(1, 0);
    cout << circleCnt << endl;

    for (int k = 0; k < T; k++) {
        int i = 0;
        int j = 0;
        cin >> i >> j;
        S = i * M + j;
        mark[S] = 1;
        tour(1, S);
        cout << cnt << endl;
        cnt = 0;
        mark.assign(N * M, 0);
    }
}

int main() {
    FastIO();
    solve();
    return 0;
}