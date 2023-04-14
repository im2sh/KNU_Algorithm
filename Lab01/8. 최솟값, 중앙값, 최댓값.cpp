#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n;
    int min = 0;
    int max = 0;
    int target = 0;
    int x;
    scanf("%d", &n);
    vector<int> arr;
    arr.emplace_back(0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        arr.emplace_back(x);
    }

    sort(arr.begin(), arr.end());

    if ((arr.size() - 1) % 2 == 0)
        target = arr[(n / 2)];
    else
        target = arr[(n / 2) + 1];

    printf("%d %d %d", arr[1], target, arr[n]);
}