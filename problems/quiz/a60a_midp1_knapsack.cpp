#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, m, i, j;
    scanf("%d%d", &n, &m);
    int v[n + 1], w[n + 1];
    int knapsack[n + 1][m + 1];
    for (i = 1; i <= n; i++) scanf("%d", &v[i]);
    for (i = 1; i <= n; i++) scanf("%d", &w[i]);
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            scanf("%d", &knapsack[i][j]);
        }
    }

    vector<int> ans;
    for (i = n; i > 0; i--) {
        if (w[i] <= m && (knapsack[i][m] == knapsack[i - 1][m - w[i]] + v[i])) {
            m -= w[i];
            ans.push_back(i);
        }
    }

    printf("%d\n", ans.size());
    for (int a : ans) printf("%d ", a);
    return 0;
}