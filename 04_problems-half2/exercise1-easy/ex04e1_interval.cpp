#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }

int main() {
    int n, i;
    scanf("%d", &n);
    vector<pair<int, int>> event(n);
    for (auto& e : event) {
        scanf("%d", &e.first);
    }
    for (auto& e : event) {
        scanf("%d", &e.second);
    }
    sort(event.begin(), event.end(), comp);

    int ans = 1;
    int prev = 0;
    for (i = 1; i < n; i++) {
        if (event[i].first >= event[prev].second) {
            ans++;
            prev = i;
        }
    }
    printf("%d", ans);
    return 0;
}