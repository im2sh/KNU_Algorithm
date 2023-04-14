void seqsearch(int n, vector<int> S, int x, int &location) {
    int &ptr = location;
    ptr = 0;
    for (int i = 1; i <= n; ++i) {
        if (S[i] == x)
            ptr = i;
    }
}