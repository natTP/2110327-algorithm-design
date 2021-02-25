#include <cstdio>

int len(int k) {
    if (k == -1) return 0;
    return 2 * len(k - 1) + k + 3;
}

char ans(int n, int k) {
    if (n > len(k)) return ans(n, k + 1);       // In 4th section
    if (n <= len(k - 1)) return ans(n, k - 1);  // In 1st section
    n -= len(k - 1);  // Remove 1st section from interest
    if (n <= k + 3) return (n == 1) ? 'g' : 'a';  // In 2nd section
    return ans(n - (k + 3), k - 1);               // In 3rd section
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%c", ans(n, 0));
    return 0;
}