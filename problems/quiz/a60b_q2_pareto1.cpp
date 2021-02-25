#include <bits/stdc++.h>

using namespace std;

// Score 50 (Time Exceeded)
vector<int> merge(vector<pair<int, int>> a, vector<int> p1, vector<int> p2) {
    vector<int> indices;
    int i, j;
    for (i = 0; i < p1.size(); i++) {
        bool pareto = true;
        for (j = 0; j < p2.size(); j++) {
            if ((a[p1[i]].first <= a[p2[j]].first) &&
                (a[p1[i]].second <= a[p2[j]].second)) {
                pareto = false;
                break;
            }
        }
        if (pareto) indices.push_back(p1[i]);
    }
    for (j = 0; j < p2.size(); j++) {
        bool pareto = true;
        for (i = 0; i < p1.size(); i++) {
            if ((a[p2[j]].first <= a[p1[i]].first) &&
                (a[p2[j]].second <= a[p1[i]].second)) {
                pareto = false;
                break;
            }
        }
        if (pareto) indices.push_back(p2[j]);
    }
    return indices;
}

vector<int> pareto(vector<pair<int, int>> a, int l, int r) {
    vector<int> indices;
    if (r - l == 1)
        indices.push_back(l);
    else {
        int m = (l + r) / 2;
        indices = merge(a, pareto(a, l, m), pareto(a, m, r));
    }
    return indices;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> a(n);
    for (int i; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[i] = make_pair(x, y);
    }
    printf("%d", pareto(a, 0, n).size());
    return 0;
}