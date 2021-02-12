#include <bits/stdc++.h>

// Optimized version of DP fibonacci. Keep only the two latest states.

int fibo(int n) {
    if (n == 0 || n == 1) return n;
    int f2 = 0;
    int f1 = 1;
    int f, i;
    for (i = 2; i <= n; i++) {
        f = f2 + f1;  // f(n) = f(n-1) + f(n-2)
        f2 = f1;
        f1 = f;
    }
    return f;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", fibo(n));
    return 0;
}