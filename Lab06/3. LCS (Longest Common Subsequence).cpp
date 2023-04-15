#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string a, b;
vector<vector<int>> lcs_arr;
vector<vector<int>> path;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void lcs() {
    int m = a.size();
    int n = b.size();

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (a[i] == b[j]) {
                lcs_arr[i][j] = lcs_arr[i - 1][j - 1] + 1;
                path[i][j] = 1;
            } else {
                lcs_arr[i][j] = max(lcs_arr[i - 1][j], lcs_arr[i][j - 1]);
                if (lcs_arr[i][j - 1] > lcs_arr[i - 1][j])
                    path[i][j] = 2; // 왼쪽 더 큼
                else
                    path[i][j] = 3; // 위가 더 큼
            }
        }
    }
}

string find_path(int i, int j) {
    if (i == 0 || j == 0)
        return "";
    else {
        if (path[i][j] == 1)
            return find_path(i - 1, j - 1) + a[i];
        else if (path[i][j] == 2)
            return find_path(i, j - 1);
        else if (path[i][j] == 3)
            return find_path(i - 1, j);

    }
}

void print_lcs() {
    for (int i = 0; i < lcs_arr.size(); i++) {
        for (int j = 0; j < lcs_arr[i].size(); j++) {
            cout << lcs_arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void print_path() {
    for (int i = 0; i < path.size(); i++) {
        for (int j = 0; j < path[i].size(); j++) {
            cout << path[i][j] << " ";
        }
        cout << "\n";
    }
}

void solve() {
    lcs();
    print_lcs();
    cout << "\n";
    print_path();
    cout << lcs_arr[a.size() - 1][b.size() - 1] << "\n";
    string result = find_path(a.size() - 1, b.size() - 1);
    cout << result << "\n";
}

void Init() {
    cin >> a >> b;
    a = "0" + a;
    b = "0" + b;

    lcs_arr.resize(a.size(), vector<int>(b.size(), 0));
    path.resize(a.size(), vector<int>(b.size(), 0));
}

int main(void) {
    fastIO();
    Init();
    solve();
}