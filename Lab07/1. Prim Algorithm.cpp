#include <iostream>
#include <utility>
#include <vector>

using namespace std;
#define INF 0xffff
typedef vector<vector<int>> matrix_t;
typedef vector<pair<int, int>> set_of_edges;
typedef pair<int, int> edge_t;
vector<int> temp;
int n, m;
int u, v, w;
matrix_t W;
set_of_edges F;

void prim(int n, matrix_t &W, set_of_edges &F) {
    int vnear, min;
    vector<int> nearest(n + 1), distance(n + 1);
    F.clear();
    for (int i = 2; i <= n; i++) {
        nearest[i] = 1;
        distance[i] = W[1][i];
    }

    for (int i = 2; i <= n; i++) {
        if (i != n)
            cout << nearest[i] << " ";
        else
            cout << nearest[i] << "\n";
    }

    for (int k = 0; k < n - 1; k++) {
        min = INF;
        for (int i = 2; i <= n; i++)
            if (0 <= distance[i] && distance[i] < min) {
                min = distance[i];
                vnear = i;
                temp.push_back(i);
            }
        F.push_back(make_pair(vnear, nearest[vnear]));
        distance[vnear] = -1;

        for (int i = 2; i <= n; i++)
            if (distance[i] > W[i][vnear]) {
                distance[i] = W[i][vnear];
                nearest[i] = vnear;
            }

        for (int i = 2; i <= n; i++) {
            if (i != n)
                cout << nearest[i] << " ";
            else
                cout << nearest[i] << "\n";
        }
    }
}

int main() {
    cin >> n >> m;
    W.resize(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        W[u][v] = w;
        W[v][u] = w;
    }

    for (int i = 1; i <= n; i++) {
        W[i][i] = 0;
    }

    prim(n, W, F);
    for (edge_t e: F) {
        u = e.first;
        v = e.second;
        cout << u << " " << v << " " << W[u][v] << endl;
    }
}