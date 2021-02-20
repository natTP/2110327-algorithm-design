#include <bits/stdc++.h>

int main() {
    int n, i, j, k, L, mini;
    scanf("%d", &n);
    int s[n + 1];
    for (i = 0; i <= n; i++) {
        scanf("%d", &s[i]);
    }

    // mcm(l,r) is the least cost to multiply A[l]...A[r].
    // 0th row and column are not used.
    int mcm[n + 1][n + 1];
    // Trivial Case: mcm[x][x] is one matrix - no multiplication.
    for (i = 1; i <= n; i++) {
        mcm[i][i] = 0;
    }
    // Fill table diagonally.
    // L is number of matrices multiplied in the current case.
    for (L = 2; L <= n; L++) {
        for (i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            mcm[i][j] = INT_MAX;
            // Find min.
            for (k = i; k < j; k++) {
                mini = mcm[i][k] + mcm[k + 1][j] + s[i - 1] * s[k] * s[j];
                if (mini < mcm[i][j]) mcm[i][j] = mini;
            }
        }
    }
    printf("%d", mcm[1][n]);
    return 0;
}