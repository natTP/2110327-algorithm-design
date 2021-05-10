// Strongly Connected Components w/ Kosaraju

#include <bits/stdc++.h>

using namespace std;

int cnt;
bool visited[1005];
stack<int> s;

// First DFS - find order of finding connected components
void dfs1(vector<vector<int>>& adj, int u) {
    if (!visited[u]) {
        visited[u] = true;
        for (int v : adj[u]) {
            dfs1(adj, v);
        }
        s.push(u);
    }
}

// Second DFS - find SCC from back to front
void dfs2(vector<vector<int>>& adj, int u) {
    if (!visited[u]) {
        cnt++;
        visited[u] = true;
        for (int v : adj[u]) {
            dfs2(adj, v);
        }
    }
}

int main() {
    int n, i, m;
    scanf("%d", &n);
    vector<vector<int>> adj(n);
    vector<vector<int>> adjT(n);
    vector<int> ans;
    for (i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &m);
        while (m--) {
            scanf("%d", &tmp);
            adj[i].push_back(tmp);
            adjT[tmp].push_back(i);
        }
    }

    for (i = 0; i < n; i++) visited[i] = false;
    for (i = 0; i < n; i++) dfs1(adjT, i);

    for (i = 0; i < n; i++) visited[i] = false;
    while (!s.empty()) {
        cnt = 0;
        dfs2(adj, s.top());
        s.pop();
        if (cnt > 0) ans.push_back(cnt);
    }
    sort(ans.begin(), ans.end());
    for (int i : ans) printf("%d ", i);
    return 0;
}