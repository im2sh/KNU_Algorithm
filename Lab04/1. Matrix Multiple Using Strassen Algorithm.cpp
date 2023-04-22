#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix_t;
int threshold;
int n;
int cnt = 0;
int k = 1;

matrix_t A, B, C;

void partition(int m, matrix_t M, matrix_t &M11, matrix_t &M12, matrix_t &M21, matrix_t &M22) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++) {
            M11[i][j] = M[i][j];
            M12[i][j] = M[i][j + m];
            M21[i][j] = M[i + m][j];
            M22[i][j] = M[i + m][j + m];
        }
}

void combine(int m, matrix_t &M, matrix_t M11, matrix_t M12, matrix_t M21, matrix_t M22) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++) {
            M[i][j] = M11[i][j];
            M[i][j + m] = M12[i][j];
            M[i + m][j] = M21[i][j];
            M[i + m][j + m] = M22[i][j];
        }
}

void resize(int n, matrix_t &mat) {
    mat.resize(n, vector<int>(n));
}

void addMat(int n, matrix_t A, matrix_t B, matrix_t &C) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subMat(int n, matrix_t A, matrix_t B, matrix_t &C) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void simpleMultiMat(int n, matrix_t A, matrix_t B, matrix_t &C) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


void printMat(int n, matrix_t M) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (M[i][j] == 0)
                continue;
            if (j == 0)
                cout << M[i][j];
            else
                cout << " " << M[i][j];
        }
        cout << "\n";
    }
}

void strassen(int n, matrix_t A, matrix_t B, matrix_t &C) {
    cnt++;
    if (n <= threshold) {
        simpleMultiMat(n, A, B, C);
    } else {
        // Define local variables here.
        matrix_t A11, A12, A21, A22;
        matrix_t B11, B12, B21, B22;
        matrix_t C11, C12, C21, C22;
        matrix_t M1, M2, M3, M4, M5, M6, M7;
        matrix_t L, R;
        int m = n / 2;
        resize(m, A11);
        resize(m, A12);
        resize(m, A21);
        resize(m, A22);
        resize(m, B11);
        resize(m, B12);
        resize(m, B21);
        resize(m, B22);
        resize(m, C11);
        resize(m, C12);
        resize(m, C21);
        resize(m, C22);

        resize(m, M1);
        resize(m, M2);
        resize(m, M3);
        resize(m, M4);
        resize(m, M5);
        resize(m, M6);
        resize(m, M7);
        resize(m, L);
        resize(m, R);


        partition(m, A, A11, A12, A21, A22);
        partition(m, B, B11, B12, B21, B22);

        addMat(m, A11, A22, L);
        addMat(m, B11, B22, R);
        strassen(m, L, R, M1);

        addMat(m, A21, A22, L);
        strassen(m, L, B11, M2);

        subMat(m, B12, B22, R);
        strassen(m, A11, R, M3);

        subMat(m, B21, B11, R);
        strassen(m, A22, R, M4);

        addMat(m, A11, A12, L);
        strassen(m, L, B22, M5);

        subMat(m, A21, A11, L);
        addMat(m, B11, B12, R);
        strassen(m, L, R, M6);

        subMat(m, A12, A22, L);
        addMat(m, B21, B22, R);
        strassen(m, L, R, M7);

        addMat(m, M1, M4, L);
        subMat(m, L, M5, R);
        addMat(m, R, M7, C11);

        addMat(m, M3, M5, C12);

        addMat(m, M2, M4, C21);

        addMat(m, M1, M3, L);
        subMat(m, L, M2, R);
        addMat(m, R, M6, C22);

        combine(m, C, C11, C12, C21, C22);
    }
}


int main() {
    cin >> n;
    cin >> threshold;

    while (k < n) {
        k *= 2;
    }

    A.resize(k, vector<int>(k, 0));
    B.resize(k, vector<int>(k, 0));
    C.resize(k, vector<int>(k, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            //cin >> A[i][j];
            A[i][j] = 1;
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            //cin >> B[i][j];
            B[i][j] = 1;
        }

    strassen(k, A, B, C);
    cout << cnt << "\n";
    printMat(k, C);


}


//#include <iostream>
//
//using namespace std;
//
//#define MAX_SIZE 10
//int A[MAX_SIZE][MAX_SIZE];
//int B[MAX_SIZE][MAX_SIZE];
//int result[MAX_SIZE][MAX_SIZE];
//int temp[MAX_SIZE][MAX_SIZE];
//int N, threshold;
//int K; // N보다 큰 거듭 제곱 수
//
//bool find2pow() {
//    if (N & (N - 1))
//        return false;
//    else
//        return true;
//}
//
//void simpleMultiple() {
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            for (int k = 0; k < N; k++) {
//                result[i][j] += A[i][k] * B[k][j];
//            }
//        }
//    }
//}
//
//void makeMat() {
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            cin >> A[i][j];
//        }
//    }
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            cin >> B[i][j];
//        }
//    }
//}
//
//void addMat() {
//    fill(&temp[0][0], &temp[0][0] + MAX_SIZE * MAX_SIZE, 0);
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            temp[i][j] = A[i][j] + B[i][j];
//        }
//    }
//}
//
//void subMat() {
//    fill(&temp[0][0], &temp[0][0] + MAX_SIZE * MAX_SIZE, 0);
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            temp[i][j] = A[i][j] - B[i][j];
//        }
//    }
//}
//
//void partition(int m, int M[MAX_SIZE][MAX_SIZE], int M11[MAX_SIZE][MAX_SIZE], int M12[MAX_SIZE][MAX_SIZE], int M21[MAX_SIZE][MAX_SIZE], int M22[MAX_SIZE][MAX_SIZE]){
//    for(int i = 0; i < m; i++){
//        for(int j =0; j<m;j++){
//            M11[i][j] = M[i][j];
//            M12[i][j] = M[i][j+m];
//            M21[i][j] = M[i+m][j];
//            M22[i][j] = M[i+m][j+m];
//        }
//    }
//}
//
//void strassen() {
//    if (N <= threshold)
//        simpleMultiple();
//    else {
//        int A11[MAX_SIZE][MAX_SIZE]; int A12[MAX_SIZE][MAX_SIZE]; int A21[MAX_SIZE]; int A22[MAX_SIZE];
//        int B11[MAX_SIZE][MAX_SIZE]; int B12[MAX_SIZE][MAX_SIZE]; int B21[MAX_SIZE]; int B22[MAX_SIZE];
//        int C11[MAX_SIZE][MAX_SIZE]; int C12[MAX_SIZE][MAX_SIZE]; int C21[MAX_SIZE]; int C22[MAX_SIZE];
//        int M1[MAX_SIZE][MAX_SIZE]; int M2[MAX_SIZE][MAX_SIZE]; int M3[MAX_SIZE]; int M4[MAX_SIZE];
//        int M5[MAX_SIZE][MAX_SIZE]; int M6[MAX_SIZE][MAX_SIZE]; int M7[MAX_SIZE];
//        int L[MAX_SIZE]; int R[MAX_SIZE];
//
//        int M = N/2;
//
//        partition(M,A,)
//    }
//}
//
//void strassen(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE])
//
//
//
//int main(void) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    cin >> N >> threshold;
//    K = N;
//    if (!find2pow()) {
//        K = 1;
//        while (K < N)
//            K *= 2;
//    }
//    N = K;
//
//    makeMat();
//
//}