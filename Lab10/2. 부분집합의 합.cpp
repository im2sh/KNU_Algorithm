#include <iostream>
#include <vector>

using namespace std;
#define MAX 100000

int n, W;
int cnt = 0;
vector<int> w(1);
vector<vector<int> > v(MAX);
int mem[MAX];
int avail;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    cin >> n >> W;

    for (int i = 0, t; i < n; i++) {
        cin >> t;
        w.push_back(t);
        avail += t;
    }

}

void printAnswer(vector<vector<int> > &v) {
    for (int i = 0; i < cnt; i++)
        for (int j = 0; j < v[i].size(); j++)
            cout << w[v[i][j]] << (j != v[i].size() - 1 ? " " : "\n");
}

bool promising(int pick, int sum, int avail) {
    if (sum + w[pick] > W) return false;
    else if (sum + avail < W) return false;
    return true;
}

void solve(int pick, int sum, int avail) {
    if (sum == W) {
        for (int i = 1; i <= pick; i++)
            if (mem[i] == 1)
                v[cnt].push_back(i);
        cnt++;
    } else {
        if (promising(pick, sum, avail) == true) {
            mem[pick] = 1;
            solve(pick + 1, sum + w[pick], avail - w[pick]);
            mem[pick] = 0;
            solve(pick + 1, sum, avail - w[pick]);
        }
    }
}

int main() {
    FastIO();
    init();
    solve(1, 0, avail);

    cout << cnt << "\n";
    if (cnt != 0)
        printAnswer(v);

    return 0;
}
