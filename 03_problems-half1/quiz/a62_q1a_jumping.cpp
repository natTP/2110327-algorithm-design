#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int n, i;
    scanf("%d", &n);
    int a[n + 1];
    int best[n + 1] = {0};
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    best[1] = a[1];
    best[2] = a[1] + a[2];
    best[3] = max(best[2], best[1]) + a[3];
    for (i = 4; i <= n; i++) {
        best[i] = max(best[i - 1], max(best[i - 2], best[i - 3])) + a[i];
    }
    printf("%d", best[n]);
    return 0;
}