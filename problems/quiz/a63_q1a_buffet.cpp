#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int n, k, m, i, p, w;
    scanf("%d%d%d", &n, &k, &m);
    int d[n + 1];
    int delish[n + 1];
    for (i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
        d[i] -= m;
        // delish[i] stores the total d from 1 to i.
        delish[i] = d[i] + delish[i - 1];
    }
    while (k--) {
        scanf("%d%d", &p, &w);
        // Search for total deliciousness of w + delish[p-1] in delish.
        int idx = lower_bound(delish, delish + n, w + delish[p - 1]) - delish;
        printf("%d\n", idx);
    }
    return 0;
}