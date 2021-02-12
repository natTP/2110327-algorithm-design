#include <bits/stdc++.h>

// Solves Max Subarray Sum by Kadane's Algorithm.
// O(n)
int kadane(int* a, int n) {
    // Calculate max suffix (suf) and mss on the fly.
    // Only keep the latest suf.
    int suf = a[0];  // Local max
    int mss = a[0];  // Global max
    for (int i = 1; i < n; i++) {
        suf = std::max(a[i], suf + a[i]);
        mss = std::max(mss, suf);
    }
    return mss;
}

int main() {
    int n, i;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("%d", kadane(a, n));
    return 0;
}