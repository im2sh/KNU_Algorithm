#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>

using namespace std;
#define INF 999999
typedef vector<vector<int>> matrix_t;

void minmult(int n, vector<int> &d, matrix_t &M, matrix_t &P);

int minimum(int i, int j, int &mink, vector<int> &d, matrix_t &M);


void minmult(int n, vector<int> &d, matrix_t &M, matrix_t &P) {
    for (int i = 1; i <= n; i++)
        M[i][i] = 0;
    for (int diagonal = 1; diagonal <= n - 1; diagonal++)
        for (int i = 1; i <= n - diagonal; i++) {
            int j = i + diagonal, k;
            M[i][j] = minimum(i, j, k, d, M);
            P[i][j] = k;
        }
}

int minimum(int i, int j, int &mink, vector<int> &d, matrix_t &M) {
    int minValue = INF, value;
    for (int k = i; k <= j - 1; k++) {
        value = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
        if (minValue > value) {
            minValue = value;
            mink = k;
        }
    }
    return minValue;
}

void order(int i, int j, matrix_t &P, string &s) {
    if (i == j)
        s += string("(") + string("A") + to_string(i) + string(")");
    else {
        int k = P[i][j];
        s += string("(");
        order(i, k, P, s);
        order(k + 1, j, P, s);
        s += string(")");
    }
}


int main() {
    int n;
    string s;
    vector<int> d;
    matrix_t M, P;
    cin >> n;

    M.resize(n + 1, vector<int>(n + 1, 0));
    P.resize(n + 1, vector<int>(n + 1, 0));

    int temp;
    for (int i = 0; i <= n; i++) {
        cin >> temp;
        d.push_back(temp);
    }
    minmult(n, d, M, P);

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (j == i)
                cout << M[i][j];
            else
                cout << " " << M[i][j];
        }
        cout << "\n";
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (j == i)
                cout << P[i][j];
            else
                cout << " " << P[i][j];
        }
        cout << "\n";
    }

    cout << M[1][n] << "\n";

    order(1, n, P, s);
    cout << s << "\n";
}

//#include <iostream>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//int d[1000];
//int M[1000][1000];
//int P[1000][1000];
//string s;
//int N;
//
//int findMin(int i, int j, int &findK) {
//    int minN = 987654321;
//    int temp;
//    for (int k = i; k <= j - 1; k++) {
//        temp = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
//        if (minN > temp) {
//            minN = temp;
//            findK = k;
//        }
//    }
//    return minN;
//}
//
//int minmult() {
//    int i, j, k, diagonal;
//    for (i = 1; i <= N; i++)
//        M[i][i] = 0;
//    for (diagonal = 1; diagonal <= N - 1; diagonal++) {
//        for (i = 1; i <= N - diagonal; i++) {
//            j = i + diagonal;
//            k = 0;
//            M[i][j] = findMin(i, j, k);
//            P[i][j] = k;
//        }
//    }
//}
//
//void order(int i, int j) {
//    if (i == j)
//        s += string("(") + string("A") + to_string(i) + string(")");
//    else {
//        int k = P[i][j];
//        s += string("(");
//        order(i, k);
//        order(k + 1, j);
//        s += string(")");
//    }
//}
//
//void Init() {
//    cin >> N;
//    for (int i = 0; i <= N; i++)
//        cin >> d[i];
//    fill(&M[0][0], &M[0][0] + 1000 * 1000, 0);
//
//}
//
//void printM() {
//    for (int i = 1; i <= N; i++) {
//        for (int j = i; j <= N; j++) {
//            if (j == i)
//                cout << M[i][j];
//            else
//                cout << " " << M[i][j];
//        }
//        cout << "\n";
//    }
//}
//
//void printP() {
//    for (int i = 1; i <= N; i++) {
//        for (int j = i; j <= N; j++) {
//            if (j == i)
//                cout << P[i][j];
//            else
//                cout << " " << P[i][j];
//        }
//        cout << "\n";
//    }
//}
//
//void solve() {
//    minmult();
//    printM();
//    printP();
//    cout << M[1][N] << "\n";
//    order(1, N);
//    cout << s;
//}
//
//int main(void) {
//    ios_base::sync_with_stdio(false);
//    cout.tie(NULL);
//    cin.tie(NULL);
//
//    Init();
//    solve();
//    return 0;
//}