#include <iostream>
#include <vector>

using namespace std;

int V, E;
int cnt = 0;
vector<vector<int> > W;
vector<int> vindex;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> V >> E;
}


bool promising(int i) {
    bool flag = true;
    if (i == V - 1 && !W[vindex[0]][vindex[V - 1]]) {
        flag = false;
    } else if (i > 0 && !W[vindex[i - 1]][vindex[i]]) {
        flag = false;
    } else {
        for (int j = 1; j < i; j++) {
            if (vindex[i] == vindex[j]) {
                flag = false;
                break;
            }
        }
    }
    return flag;
}

void solve(int i) {
    if (promising(i)) {
        if (i == V - 1) {
            cnt++;
        } else {
            for (int j = 2; j <= V; j++) {
                vindex[i + 1] = j;
                solve(i + 1);
            }
        }
    }
}

int main() {
    FastIO();
    Init();
    int s, e;

    vindex.resize(V + 1, 1);
    W.resize(V + 1, vector<int>(V + 1, false));

    for (int i = 0; i < E; i++) {
        cin >> s >> e;
        W[s][e] = W[e][s] = true;
    }

    solve(0);

    cout << cnt;

    return 0;
}