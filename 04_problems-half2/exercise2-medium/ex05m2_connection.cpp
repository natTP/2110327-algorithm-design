#include <bits/stdc++.h>

using namespace std;

int cnt, k;
bool selected[1005];

// u = current, d = degree
void dfs(vector<vector<int>>& adj, int u, int d) {
    if (!selected[u]) {
        selected[u] = true;
        cnt++;
    }
    if (d == k) return;
    for (int v : adj[u]) dfs(adj, v, d + 1);
}

int main() {
    int n, e, i, j;
    scanf("%d%d%d", &n, &e, &k);
    vector<vector<int>> g(n);
    while (e--) {
        scanf("%d%d", &i, &j);
        g[i].push_back(j);
        g[j].push_back(i);
    }
    int ans = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) selected[j] = false;
        cnt = 0;
        dfs(g, i, 0);
        if (cnt > ans) ans = cnt;
    }
    printf("%d", ans);
    return 0;
}