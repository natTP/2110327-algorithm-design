#include <bits/stdc++.h>

using namespace std;

int r, c;
char maze[105][105];
bool visited[105][105];
vector<pair<int, int>> direction = {make_pair(1, 0), make_pair(-1, 0),
                                    make_pair(0, 1), make_pair(0, -1)};

int bfs(int sr, int sc, int tr, int tc) {
    queue<pair<int, pair<int, int>>> q;  // dist, <row, column>
    q.emplace(0, make_pair(sr, sc));
    visited[sc][sc] = true;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int d = p.first;
        int r0 = p.second.first;
        int c0 = p.second.second;
        if (r0 == tr && c0 == tc) return d;
        for (auto dir : direction) {
            int r1 = r0 + dir.first;
            int c1 = c0 + dir.second;
            if ((0 <= r1 && r1 < r && 0 <= c1 && c1 < c)) {
                if (maze[r1][c1] == '#') continue;
                if (!visited[r1][c1]) {
                    q.emplace(d + 1, make_pair(r1, c1));
                    visited[r1][c1] = true;
                }
            }
        }
    }
    return -1;
}

int main() {
    int i, j;
    scanf("%d%d", &r, &c);
    for (i = 0; i < r; i++) {
        scanf("%s", maze[i]);
    }
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            visited[i][j] = false;
        }
    }
    printf("%d", bfs(0, 0, r - 1, c - 1));
    return 0;
}