#include <bits/stdc++.h>

using namespace std;

/* Pareto's condition: no point j exists where X(j) >= X(i) && Y(j) >= Y(i).

This means that for every point that isn't itself, a pareto will have either a
larger X or a larger Y (or both) than that point. */

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> a(n);
    for (int i; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[i] = make_pair(x, y);
    }
    sort(a.begin(), a.end());
    int maxi = a[n - 1].second;
    // There is at least one pareto, which is the point with max X (point n-1).
    // This point is a pareto because it has a larger X than every other point.
    int ans = 1;
    // Other paretos will have to have a larger Y than the points with a larger
    // X than them.
    for (int i = n - 1; i >= 0; i--) {
        if (a[i].second > maxi) {
            maxi = a[i].second;
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}