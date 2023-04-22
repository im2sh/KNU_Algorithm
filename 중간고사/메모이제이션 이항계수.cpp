#include <iostream>
#include <vector>

using namespace std;
int N, K;
int dp[50004];

//int bin(int n, int k)
//{
//    for (int i = 0; i <= n; i++)
//    {
//        // 0열은 1이므로 초기화
//        int prev = 0, preprev = 1;
//        for (int j = 0; j <= min(i, k); j++)
//        {
//            //if (j == 0 || j == i) dp[j] = 1;
//            if (j == 1 or i == j) dp[j] = 2;
//            else
//            {
//                prev = dp[j];   //prev문은 preprev를 저장하기 위한 변수
//                dp[j] = (dp[j] + preprev) % 1000;
//                preprev = prev;
//            }
//        }
//    }
//    return dp[k];
//}

int bin2(int n, int k) {
    vector<vector<long long>> B(n + 1, vector<long long>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            if (j == 1 or j == i) B[i][j] = 2;
            else B[i][j] = (B[i - 1][j] + B[i - 1][j - 1]) % 1000;
        }
    }
    return B[n][k];
}

int main(void) {
    cin >> N >> K;
    cout << bin2(N, K) << "\n";
}