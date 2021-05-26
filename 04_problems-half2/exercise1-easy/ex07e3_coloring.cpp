#include <bits/stdc++.h>

using namespace std;

bool visited[55];
int color[55];

// BFS and recolor each node found

int main() {
    int n, e;
    scanf("%d%d", &n, &e);
    vector<vector<int>> adj(n);
    while (e--) {
        int i, j;
        scanf("%d%d", &i, &j);
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j : adj[i]) printf("%d ", j);
    //     printf("\n");
    // }

    for (int i = 0; i < n; i++) {
        color[i] = 0;
        visited[i] = false;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        visited[i] = true;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (color[v] == color[u]) color[v]++;
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    // final result still has errors

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (color[i] > ans) ans = color[i];
        printf("%d ", color[i]);
    }
    printf("\n%d", ans + 1);

    return 0;
}

/*
>>> 70/100
15 50
6 11
2 11
8 11
1 3
5 7
4 5
2 7
6 10
5 8
0 6
11 12
10 13
7 12
2 6
0 1
7 14
3 11
3 7
6 8
9 13
2 14
4 6
6 7
1 5
4 11
13 14
4 14
2 12
1 8
7 9
0 14
5 11
10 12
6 9
1 14
6 14
8 13
6 13
0 10
8 14
5 13
4 8
9 10
11 13
4 9
9 11
3 10
2 10
0 9
10 14

Desired Out: 5
This Code: 4
*/