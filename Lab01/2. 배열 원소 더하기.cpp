int sum(int n, vector<int> S) {
    int result = 0;
    for (int i = 1; i <= n; ++i) {
        result += S[i];
    }
    return result;
}