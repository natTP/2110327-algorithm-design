#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int n, i, j, tmp;
    scanf("%d", &n);
    int a[3][2 * n];  // Total number of diagsums (max length) = 2n-1
    for (j = 0; j < 2 * n; j++) a[0][j] = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &tmp);
            // Array a contains value of subdiagsum with tmp at the end.
            if (a[0][i + n - j] == 0) {
                a[1][i + n - j] = tmp;
                a[2][i + n - j] = tmp;
                a[0][i + n - j] = 1;
            } else {
                // Row 1: Current chain (Local Max)
                a[1][i + n - j] = max(tmp, a[1][i + n - j] + tmp);
                // Row 2: Max chain of this diagsum (Global Max)
                a[2][i + n - j] = max(a[2][i + n - j], a[1][i + n - j]);
            }
        }
    }
    int ans = a[2][1];
    for (j = 2; j < 2 * n; j++) {
        ans = max(ans, a[2][j]);
    }
    printf("%d", ans);
    return 0;
}