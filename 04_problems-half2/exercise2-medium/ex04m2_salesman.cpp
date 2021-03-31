#include <algorithm>
#include <cmath>
#include <cstdio>

// time[i] contains time to travel from 0 to i.
int time[1005];
int totalTime = 0;

int shortestPath(int a, int b) {
    int cw = abs(time[a] - time[b]);
    return std::min(cw, totalTime - cw);
}

int main() {
    int n, m, i;
    scanf("%d%d", &n, &m);

    int order[m + 1];
    for (i = 0; i < m; i++) {
        scanf("%d", &order[i]);
    }
    order[m] = order[0];

    time[0] = 0;
    for (i = 1; i <= m; i++) {
        scanf("%d", &time[i]);
        totalTime += time[i];
        time[i] += time[i - 1];
    }

    int a, b, ans;
    while (n--) {
        scanf("%d%d", &a, &b);
        ans = 0;
        for (i = 0; i < m; i++) {
            // Find shortest path from order[i] to order[i+1]
            // Case 1 : Without warp
            int minPath = shortestPath(order[i], order[i + 1]);
            // Case 2 : With warp
            int warpAB =
                shortestPath(order[i], a) + shortestPath(b, order[i + 1]);
            int warpBA =
                shortestPath(order[i], b) + shortestPath(a, order[i + 1]);
            minPath = std::min(minPath, std::min(warpAB, warpBA));
            ans += minPath;
        }
        printf("%d\n", ans);
    }

    return 0;
}