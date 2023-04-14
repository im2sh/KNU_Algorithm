#include <iostream>

using namespace std;
int cnt;
int DP[1000][1000];

int bin(int N, int K) {
    cnt++; // 함수 호출 횟수 카운트
    if (K == 0 || N == K)
        DP[N][K] = 1;
    else if (DP[N][K] == 0)
        DP[N][K] = (bin(N - 1, K) + bin(N - 1, K - 1)) % 10007; // memoize using recursive call

    return DP[N][K]; // return memoized value
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    int result = bin(N, K);
    cout << result << "\n" << cnt;
    return 0;
}