#include <bits/stdc++.h>

int bsearch(int a[], int k, int start, int stop) {
    if (start > stop) {
        if (start == 0) return -1;
        return a[stop];
    }
    int m = (start + stop) / 2;
    if ((a[m] <= k) && (k < a[m + 1])) return a[m];
    if (a[m] > k) {  // Look left, but don't need to look at m anymore
        return bsearch(a, k, start, m - 1);
    } else {
        return bsearch(a, k, m + 1, stop);
    }
}

int main() {
    int n, m, i, q;
    scanf("%d%d", &n, &m);
    int a[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    while (m--) {
        scanf("%d", &q);
        printf("%d\n", bsearch(a, q, 0, n - 1));
    }
    return 0;
}