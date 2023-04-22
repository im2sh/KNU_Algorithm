#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>

using namespace std;
#define INF 999
typedef vector<vector<int>> matrix_t;

struct List {
    vector<int> listu;
    vector<int> listv;
};

matrix_t W, D, P;
vector<int> p;
List list;
int N, M;
int i, j, weight;
int u, v, n;

void display() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << D[i][j] << " ";
        }
        cout << "\n";
    }
}

void floyd_m(int n, matrix_t &W, matrix_t &D, matrix_t &P) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            D[i][j] = W[i][j];
            P[i][j] = 0;
        }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (D[i][j] > D[i][k] + D[k][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k;
                }
}

void path(matrix_t &P, int u, int v, vector<int> &p) {
    int k = P[u][v];
    if (k != 0) {
        path(P, u, k, p);
        p.push_back(k);
        path(P, k, v, p);
    }
}

int main() {


    cin >> N >> M;

    W.resize(N + 1, vector<int>(N + 1, INF));
    D.resize(N + 1, vector<int>(N + 1));
    P.resize(N + 1, vector<int>(N + 1));

    for (int k = 1; k <= M; k++) {
        cin >> i >> j >> weight;
        W[i][j] = weight;
    }

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        list.listu.push_back(u);
        list.listv.push_back(v);
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (i == j)
                W[i][j] = 0;


    floyd_m(N, W, D, P);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (j == 1)
                cout << D[i][j];
            else
                cout << " " << D[i][j];
        }
        cout << "\n";
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (j == 1)
                cout << P[i][j];
            else
                cout << " " << P[i][j];
        }
        cout << "\n";
    }

    for (i = 0; i < n; i++) {
        int x = list.listu[i], y = list.listv[i];
        if (D[x][y] == INF)
            cout << "NONE" << "\n";
        else {
            path(P, x, y, p);

            cout << x << " ";

            for (int k = 0; k < p.size(); k++)
                cout << p[k] << " ";

            cout << y << "\n";
            p.clear();
        }

    }


}
