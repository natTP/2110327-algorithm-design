#include <bits/stdc++.h>

int main() {
    int n, i;
    scanf("%d", &n);
    int c[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    // best is the answer from c[0...i-1]
    // when c[i] is not selected (0) or selected (1).
    int best[n][2];
    best[0][0] = 0;
    best[0][1] = c[0];
    for (i = 1; i < n; i++) {
        best[i][0] = std::max(best[i - 1][1], best[i - 1][0]);
        best[i][1] = best[i - 1][0] + c[i];
        // c[i] selected: can only NOT select c[i-1]
    }
    printf("%d", std::max(best[n - 1][0], best[n - 1][1]));
    return 0;
}