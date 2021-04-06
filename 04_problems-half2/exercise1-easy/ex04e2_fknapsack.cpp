#include <bits/stdc++.h>

using namespace std;

bool comp(pair<double, double> a, pair<double, double> b) {
    return (a.first / a.second) > (b.first / b.second);
}

int main() {
    double w;
    int n, i;
    scanf("%lf%d", &w, &n);
    vector<pair<double, double>> items(n);
    for (auto& item : items) {
        scanf("%lf", &item.first);
    }
    for (auto& item : items) {
        scanf("%lf", &item.second);
    }
    sort(items.begin(), items.end(), comp);

    double sumW = 0, sumV = 0, fraction;
    for (i = 0; i < n && sumW <= w; i++) {
        fraction = min(items[i].second, w - sumW) / items[i].second;
        sumW += fraction * items[i].second;
        sumV += fraction * items[i].first;
    }
    printf("%.4lf", sumV);
    return 0;
}