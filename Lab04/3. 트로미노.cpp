#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix_t;

matrix_t board;
int cnt = 0;

void resize(int n, matrix_t &mat) {
    mat.resize(n, vector<int>(n, 0)); // n*n 사이즈로 정의 후 0으로 초기화
}

void print_board(int n, matrix_t M) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << M[i][j];
            if (!(j == n - 1)) {
                cout << " "; // 마지막 스페이스 출력 방지용
            }
        }
        cout << endl;
    }
}

int whereis(int n, int srow, int scol, int row, int col) {
    int m = n / 2;
    if (row - srow < m) {
        if (col - scol < m) {
            return 1;
        } else {
            return 2;
        }
    } else {
        if (col - scol < m) {
            return 3;
        } else {
            return 4;
        }
    }
}

void fill(int cnt, matrix_t &board, int srow, int scol, int where) {
    if (where != 1) {
        board[srow][scol] = cnt;
    }
    if (where != 2) {
        board[srow][scol + 1] = cnt;
    }
    if (where != 3) {
        board[srow + 1][scol] = cnt;
    }
    if (where != 4) {
        board[srow + 1][scol + 1] = cnt;
    }
}

int hole_row(int part, int where, int n, int srow, int row) {
    int m = n / 2;
    if (part != where) {
        row = srow + m - 1;

        if (part == 3 || part == 4) {
            row += 1;
        }
    }
    return row;
}

int hole_col(int part, int where, int n, int scol, int col) {
    int m = n / 2;
    if (part != where) {
        col = scol + m - 1;

        if (part == 2 || part == 4) {
            col += 1;
        }
    }
    return col;
}

void tromino(int n, matrix_t &board, int srow, int scol, int row, int col) {
    cnt++;

    int where = whereis(n, srow, scol, row, col);
    if (n == 2) {
        fill(cnt, board, srow, scol, where);
    } else {
        int m = n / 2;
        int hrow, hcol;

        fill(cnt, board, srow + m - 1, scol + m - 1, where);
        hrow = hole_row(1, where, n, srow, row);
        hcol = hole_col(1, where, n, scol, col);
        tromino(m, board, srow, scol, hrow, hcol);

        hrow = hole_row(2, where, n, srow, row);
        hcol = hole_col(2, where, n, scol, col);
        tromino(m, board, srow, scol + m, hrow, hcol);

        hrow = hole_row(3, where, n, srow, row);
        hcol = hole_col(3, where, n, scol, col);
        tromino(m, board, srow + m, scol, hrow, hcol);

        hrow = hole_row(4, where, n, srow, row);
        hcol = hole_col(4, where, n, scol, col);
        tromino(m, board, srow + m, scol + m, hrow, hcol);
    }
}

int main() {
    int n;
    cin >> n;
    resize(n, board);

    int row, col;
    cin >> row >> col;

    int srow = 0;
    int scol = 0;
    tromino(n, board, srow, scol, row, col);
    print_board(n, board);

    return 0;
}

