#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int cnt = 0;
vector<int> arr;

void partition(int low, int high, int &pivotpoint) {
    int i, j, pivotitem;

    pivotitem = arr[low];
    j = low;
    for (i = low + 1; i <= high; i++) {
        if (arr[i] < pivotitem) {
            j++;
            swap(arr[i], arr[j]);
            cnt++; // swap 연산의 실행 횟수 카운트
        }
    }
    pivotpoint = j;
    swap(arr[low], arr[pivotpoint]);
    cnt++; // swap 연산의 실행 횟수 카운트
}

void quicksort(int low, int high) {
    int pivotpoint;
    if (low < high) {
        partition(low, high, pivotpoint);
        quicksort(low, pivotpoint - 1);
        quicksort(pivotpoint + 1, high);
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

    quicksort(1, N);
    for (int i = 0; i < N; i++) {
        if (i != N)
            cout << arr[i] << " ";
        else
            cout << arr[i];
    }
    cout << "\n";
    cout << cnt;
    return 0;
}
