#include <bits/stdc++.h>

int main() {
    int cap, n, i, j;
    scanf("%d%d", &cap, &n);
    // n items, each with its weight w[i] and price p[i].
    int w[n], p[n];
    for (i = 0; i < n; i++) {
        scanf("%d%d", &w[i], &p[i]);
    }
    // Table with n rows and cap columns.
    // i is the item (0 to n-1)
    // j is the remaining weight available (0 to cap).
    int K[n][cap] = {0};
    for (i = 0; i < n; i++) {  // For each item
        for (j = 0; j <= cap; j++) {
            if (w[i] > j)  // Case: Can't select this item.
                K[i][j] = K[i - 1][j];
            else  // Case: Can select this item.
                K[i][j] = std::max(K[i - 1][j - w[i]] + p[i], K[i - 1][j]);
            // Best case is the max of (select, not select)
        }
    }
    return 0;
}

// Q: Does this code generate unneeded subproblems?