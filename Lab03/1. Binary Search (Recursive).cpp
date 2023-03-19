#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cnt = 0;


int bisearch(vector<int> arr, int low, int high, int target) {
    int mid;
    if (low > high) {
        return 0;
    } else {
        cnt++;
        mid = (low + high) / 2;
        if (target == arr[mid])
            return mid;
        else if (target < arr[mid])
            return bisearch(arr, low, mid - 1, target);
        else
            return bisearch(arr, mid + 1, high, target);
    }
}

int main(void) {
    int N, M;
    int x;
    int r;
    vector<int> arr;
    int result = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> r;
        arr.push_back(r);
    }
    sort(arr.begin(), arr.end() + 1);
    for (int i = 0; i < M; i++) {
        cnt = 0;
        cin >> x;
        result = bisearch(arr, 0, N, x);
        cout << cnt << " " << result << "\n";
    }
    return 0;
}