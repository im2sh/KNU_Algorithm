// page.61
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> D;      // deadline
vector<int> profit; // profit
vector<int> S;         // feasible sequence

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    int temp;
    D.push_back(0);
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        D.push_back(temp);
    }
    profit.push_back(0);
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        profit.push_back(temp);
    }
}

void solve() {
    // initialize
    S.push_back(0);
    S.push_back(1);

    // Greedy
    for (int i = 2; i <= N; i++) {

        vector<int> T = S;

        int idx = 0;
        for (int t = T.size() - 1; t > 0; t--) {
            if (D[T[t]] <= D[i]) {
                idx = t;
                break;
            }
        }

        T.insert(T.begin() + idx + 1, i);

        int feasible = 1;
        for (int t = 1; t < T.size(); t++) {
            if (D[T[t]] < t) {
                feasible = 0;
                break;
            }
        }

        if (feasible) S = T;
    }

    int ans = 0;
    for (int i = 1; i < S.size(); i++) ans += profit[S[i]];

    cout << ans << "\n";
    for (int i = 1; i < S.size(); i++) cout << profit[S[i]] << (i != S.size() - 1 ? " " : "");
}

int main() {
    FastIO();
    Init();
    solve();
    return 0;
}



