void binsearch(int n, vector<int> S, int x, int &location) {
    int low, high, mid;
    low = 1;
    high = n;
    location = 0;
    while (low <= high && location == 0) {
        mid = (low + high) / 2;
        if (x == S[mid])
            location = mid;
        else if (x < S[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
}