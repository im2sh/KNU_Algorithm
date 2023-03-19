#include <iostream>
#include <vector>

using namespace std;

int N;
int cnt = 0;
vector<int> arr;

void merge2(int low, int mid, int high) {
    int i, j, k;
    vector<int> U(high - low + 1);

    i = low;
    j = mid + 1;
    k = 0;
    while (i <= mid && j <= high) {
        U[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
        cnt++; // S의 원소끼리의 비교 연산 횟수 카운트. cnt는 전역 변수
    }

    if (i > mid)
        while (j <= high) U[k++] = arr[j++];
    else
        while (i <= mid) U[k++] = arr[i++];

    for (int t = low; t <= high; t++)
        arr[t] = U[t - low];
}

void mergesort2(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort2(low, mid);
        mergesort2(mid + 1, high);
        merge2(low, mid, high);
    }
}

int main(void) {
    int t;
    cin >> N;
    arr.push_back(0);
    for (int i = 0; i < N; i++) {
        cin >> t;
        arr.push_back(t);
    }

    mergesort2(1, N);
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