#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;
vector<pair<int, int>> tot;
int N;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }

    sort(v.begin(), v.end(), cmp);

    int ret = 1;
    int end_T = v[0].second;
    tot.push_back({v[0].first, v[0].second});

    for (int i = 1; i < N; i++) {
        if (v[i].first >= end_T) {
            end_T = v[i].second;
            ret += 1;
            tot.push_back({v[i].first, v[i].second});
        }
    }

    cout << ret << "\n";
    for (pair<int, int> temp: tot) {
        cout << temp.first << " " << temp.second << "\n";
    }
}