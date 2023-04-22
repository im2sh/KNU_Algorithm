#define INF 999999

#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int>> matrix;

void dijkstra(int n, matrix &t, vector<pair<int, int>> &F);

int find(vector<int> &v, int n);

int n, m;

vector<int> touch(n + 1), length(n + 1);
int start = 1;

void dijkstra(int n, matrix &t, vector<pair<int, int>> &F) {
    int vnear, min;
    F.clear();
    for (int i = 1; i <= n; i++) {
        if (i == start) {
            continue;
        }
        touch[i] = start;
        length[i] = t[start][i];
    }
    for (int i = 1; i <= n; i++) {

        if (i == start) {
            continue;
        }

        if (i < n)
            cout << touch[i] << " ";
        else
            cout << touch[i];
    }
    cout << endl;

    for (int i = 0; i < n - 1; i++) {
        min = INF;
        for (int i = 1; i <= n; i++) {

            if (i == start) {
                continue;
            }

            if (0 <= length[i] && length[i] < min) {
                min = length[i];
                vnear = i;
            }
        }
        F.push_back(make_pair(touch[vnear], vnear));
        for (int i = 1; i <= n; i++) {
            if (i == start) {
                continue;
            }

            if (length[i] > length[vnear] + t[vnear][i]) {
                length[i] = length[vnear] + t[vnear][i];
                touch[i] = vnear;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (i == start) {
                continue;
            }

            if (i < n)
                cout << touch[i] << " ";
            else
                cout << touch[i];
        }
        cout << endl;
        length[vnear] = -1;
    }
}


int main() {
    cin >> n >> m;
    touch.resize(n + 1, 0);
    length.resize(n + 1, 0);

    matrix a(n + 1, vector<int>(n + 1, INF));

    vector<pair<int, int>> b;
    vector<int> weight;
    for (int i = 0; i < m; i++) {
        int s, f, w;
        cin >> s >> f >> w;
        a[s][f] = w;
    }

    //cout << "\n";
    dijkstra(n, a, b);
    for (int i = 0; i < b.size(); i++) {
        int u = b[i].first, v = b[i].second;

        cout << u << " " << v << " " << a[u][v] << endl;
    }

    int number, aa;
    cin >> number;
    for (int i = 0; i < number; i++) {
        cin >> aa;
        vector<int> bb;
        while (aa != start) {
            bb.push_back(aa);
            aa = touch[aa];
        }
        bb.push_back(start);
        for (int i = bb.size() - 1; i >= 0; i--) {
            if (i > 0)
                cout << bb[i] << " ";
            else
                cout << bb[i];
        }
        cout << endl;
    }
}
