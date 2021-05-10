// Topological Sort

#include <bits/stdc++.h>

using namespace std;

int visited[1005];  // 0 - not visited, 1 = entered, 2 = complete
int exitTime[1005];
int t = 0;

bool comp(int a, int b) { return exitTime[a] > exitTime[b]; }

void dfs(vector<vector<int>>& adj, int u) {
    visited[u] = 1;
    t++;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(adj, v);
    }
    visited[u] = 2;
    exitTime[u] = ++t;
}

int main() {
    int n, i, m;
    scanf("%d", &n);
    vector<vector<int>> adj(n);
    vector<int> ans;
    for (i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &m);
        while (m--) {
            scanf("%d", &tmp);
            adj[tmp].push_back(i);
        }
        ans.push_back(i);
    }

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    t = 0;
    for (i = 0; i < n; i++) {
        if (!visited[i]) dfs(adj, i);
    }
    sort(ans.begin(), ans.end(), comp);
    // or just use a stack instead of sorting by endtime
    for (int i : ans) printf("%d ", i);
    return 0;
}