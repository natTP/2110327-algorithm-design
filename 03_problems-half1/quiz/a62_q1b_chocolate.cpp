#include <cstdio>

int main() {
    int n, k, i, j;
    scanf("%d%d", &n, &k);
    int s[k];
    for (i = 0; i < k; i++) {
        scanf("%d", &s[i]);
    }
    int ways[n + 1] = {0};
    ways[0] = 1;
    ways[1] = 1;
    for (i = 2; i <= n; i++) {
        for (j = 0; j < k; j++) {
            if (i >= s[j])
                ways[i] = (ways[i] + ways[i - s[j]] % 1000003) % 1000003;
        }
    }
    printf("%d", ways[n]);
    return 0;
}