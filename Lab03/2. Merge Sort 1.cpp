#include <iostream>
#include <vector>

using namespace std;

int N;
int cnt = 0;

void merge(int h, int m, vector<int> &u, vector<int> &v, vector<int> &s) {
    int i = 1, j = 1, k = 1;
    while (i <= h && j <= m)
        s[k++] = (u[i] < v[j]) ? u[i++] : v[j++];
    if (i > h)
        while (j <= m)
            s[k++] = v[j++];
    else
        while (i <= h)
            s[k++] = u[i++];

}

void mergesort(int n, vector<int> &S) {
    if (n > 1) {
        int h = n / 2, m = n - h;
        vector<int> U(h + 1), V(m + 1);
        cnt += h + m; // 추가 메모리 크기 카운트. cnt는 전역 변수
        for (int i = 1; i <= h; i++)
            U[i] = S[i];
        for (int i = h + 1; i <= n; i++)
            V[i - h] = S[i];
        mergesort(h, U);
        mergesort(m, V);
        merge(h, m, U, V, S);
    }
}

int main(void) {
    int t;
    cin >> N;
    vector<int> arr;
    arr.push_back(0);
    for (int i = 0; i < N; i++) {
        cin >> t;
        arr.push_back(t);
    }

    mergesort(N, arr);
    for (int i = 1; i <= N; i++) {
        if (i != N)
            cout << arr[i] << " ";
        else
            cout << arr[i];
    }
    cout << "\n";
    cout << cnt;
    return 0;
}