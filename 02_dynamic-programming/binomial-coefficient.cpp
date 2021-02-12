#include <bits/stdc++.h>

int table[1000][1000];

// C(n,r) = C(n-1,r) + C(n-1,r-1)
// Use the concept of Pascal's Triangle to fill in table.
int binomial(int n, int r) {
    int i, j;
    // Initialize table with 1s at edge.
    for (i = 0; i <= n; i++) {
        table[i][0] = 1;
        table[i][i] = 1;
    }
    // Fill in table.
    for (i = 1; i <= n; i++) {
        for (j = 1; j < i; j++) {
            table[i][j] = table[i - 1][j] + table[i - 1][j - 1];
        }
    }
    return table[n][r];
}

// Q: How to avoid solving unneeded subproblems?

int main() {
    int n, r;
    scanf("%d%d", &n, &r);
    printf("%d", binomial(n, r));
    return 0;
}