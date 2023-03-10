#include <iostream>
#include <cmath>

using namespace std;

typedef long long long_t;

long_t fun(long_t n) {
    return pow(8, (long long) (log2(n) / log2(4)) + 1);
}

int main() {
    long_t n;
    scanf("%lld", &n);
    printf("%lld", fun(n));
}