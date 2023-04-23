#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;
vector<pair<int, int>> result;
int N;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void Init() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }

    sort(v.begin(), v.end(), cmp);
}

void solve() {
    int ret = 1;
    int end_T = v[0].second;
    result.push_back({v[0].first, v[0].second});

    for (int i = 1; i < N; i++) {
        if (v[i].first >= end_T) {
            end_T = v[i].second;
            ret += 1;
            result.push_back({v[i].first, v[i].second});
        }
    }

    cout << ret << "\n";
    for (pair<int, int> temp: result) {
        cout << temp.first << " " << temp.second << "\n";
    }
}

int main() {
    FastIO();
    Init();
    solve();
    return 0;
}