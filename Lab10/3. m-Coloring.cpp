#include <iostream>
#include <vector>

using namespace std;

int V, E;
int cnt = 0;
vector<vector<int> > W;
vector<int> color;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> V >> E;
}

bool promising(int v, int c) {
    for (int i = 1; i < v; i++)
        if (W[v][i] == true && c == color[i])
            return false;
    return true;
}

void printColors() {
    for (int i = 1; i <= V; i++) {
        cout << color[i] << " ";
    }
    cout << "\n";
}

void solve(int v, int C) {
    if (v > V) {
        cnt++;
    } else {
        for (int c = 1; c <= C; c++) {
            if (promising(v, c) == true) {
                color[v] = c;
                solve(v + 1, C);
            }
        }
    }
}

int main() {
    int s, e;
    FastIO();
    Init();

    color.resize(V + 1, 0);
    W.resize(V + 1, vector<int>(V + 1, false));

    for (int i = 0; i < E; i++) {
        cin >> s >> e;
        W[s][e] = W[e][s] = true;
    }

    for (int i = 1; i <= V; i++) {
        solve(1, i);
        if (cnt != 0) break;
    }

    int t = cnt;
    int div = 0;
    do {
        div += 1;
        t /= div;
    } while (t != 1);
    cout << div << "\n" << cnt;

    return 0;
}