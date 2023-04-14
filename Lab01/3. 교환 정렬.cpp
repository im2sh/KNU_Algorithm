void exchange(int n, vector<int> &S) {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (S[i] > S[j])
                swap(S[i], S[j]);
        }
    }
}