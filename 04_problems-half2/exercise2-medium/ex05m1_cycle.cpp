#include <bits/stdc++.h>

using namespace std;

int visited[1005];
bool isCycle;

void dfs(vector<vector<int>>& adj, int u, int prev) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (v == prev) continue;  // ignore previous node you just came from
        if (visited[v] == 1) {
            isCycle = true;
            return;
        }
        dfs(adj, v, u);
    }
    visited[u] = 2;
    if (isCycle) return;
}

int main() {
    int t, n, e, i, j;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &e);
        vector<vector<int>> g(n);
        while (e--) {
            scanf("%d%d", &i, &j);
            g[i].push_back(j);
            g[j].push_back(i);
        }
        isCycle = false;
        for (i = 0; i < n; i++) visited[i] = 0;
        for (i = 0; i < n; i++) {
            if (!visited[i]) dfs(g, i, -1);
            if (isCycle) break;
        }
        printf(isCycle ? "YES\n" : "NO\n");
    }
    return 0;
}