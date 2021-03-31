#include <algorithm>
#include <cstdio>

int main() {
    int n, i;
    int a = 0, b = 0;
    scanf("%d", &n);
    int va[n], vb[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &va[i]);
        vb[i] = va[i];
    }
    std::sort(vb, vb + n);
    for (i = 0; i < n; i++) {
        if (va[i] < vb[i]) a++;
        if (va[i] > vb[i]) b++;
    }
    printf("%d", std::max(a, b));
    return 0;
}