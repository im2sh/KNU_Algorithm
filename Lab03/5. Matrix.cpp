#include <iostream>
#include <vector>

using namespace std;
int N, B;

vector<vector<int>> temp;

vector<vector<int>> calcuM(vector<vector<int>> original, vector<vector<int>> temp) {
    vector<vector<int>> result_temp(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result_temp[i][j] += ((original[i][k]) * (temp[k][j])) % 1000;
                result_temp[i][j] %= 1000;
            }
        }
    }
    return result_temp;
}

vector<vector<int>> powerM(vector<vector<int>> arr, int B) {
    if (B == 1)
        return arr;
    if (B % 2 == 0) {
        temp = powerM(arr, B / 2);
        return calcuM(temp, temp);
    } else {
        temp = powerM(arr, B - 1);
        return calcuM(arr, temp);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> B;
    vector<vector<int>> arr(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> result = powerM(arr, B);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j == N - 1)
                cout << result[i][j] << "\n";
            else
                cout << result[i][j] << " ";
        }
    }
    return 0;
}
