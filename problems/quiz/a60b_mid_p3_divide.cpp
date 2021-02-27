#include <cstdio>

int main() {
    int n, k, i, j;
    int a, b;
    scanf("%d%d", &n, &k);
    int divide[n + 1][k + 1] = {0};
    for (i = 1; i <= n; i++) divide[i][1] = 1;
    for (i = 1; i <= n; i++) {
        for (j = 2; j <= k; j++) {
            if (i < j)
                divide[i][j] = 0;
            else if (i == j)
                divide[i][j] = 1;
            else
                divide[i][j] = j * (divide[i - 1][j] % 1997) +
                               (divide[i - 1][j - 1] % 1997);
        }
    }
    printf("%d", divide[n][k] % 1997);
    return 0;
}