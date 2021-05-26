// CODE DOES NOT WORK

#include <bits/stdc++.h>

using namespace std;

// Max-Profit Search in State Space with Upper Bound
int n;
double vmax, w;

class pqcomp {
   public:
    bool operator()(const pair<vector<int>, double>& a,
                    const pair<vector<int>, double>& b) const {
        return a.second < b.second;
    }
};

typedef priority_queue<pair<vector<int>, double>,
                       std::vector<pair<vector<int>, double>>, pqcomp>
    pqtype;

bool comp(pair<double, double> a, pair<double, double> b) {
    return (a.first / a.second) > (b.first / b.second);
}

// Calculate max profit from fractional knapsack of items m+1 to n
double maxprofit(vector<pair<double, double>>& items, double W, int m) {
    double sumW = 0, sumV = 0, fraction;
    for (int i = m; i < items.size() && sumW <= W; i++) {
        fraction = min(items[i].second, W - sumW) / items[i].second;
        sumW += fraction * items[i].second;
        sumV += fraction * items[i].first;
    }
    return sumV;
}

double sum(int mode, vector<pair<double, double>>& items, vector<int>& a,
           int m) {
    double ans = 0;
    if (mode == 1)
        for (int i = 0; i < m; i++) ans += items[i].first * a[i];
    else if (mode == 2)
        for (int i = 0; i < m; i++) ans += items[i].second * a[i];
    return ans;
}

void knapsack(vector<pair<double, double>>& items, int m) {
    pqtype pq;  // answer, profit
    vector<int> ans(n + 1, 0);
    pq.push(make_pair(ans, maxprofit(items, w, 0)));
    while (!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        vector<int> a = x.first;
        double vup = x.second;
        if (vup <= vmax) break;
        if (m == n) {
            if (vup > vmax) vmax = vup;
        } else {
            a[m + 1] = 0;
            double sumV = sum(1, items, a, m);
            double sumW = sum(2, items, a, m);
            double profit = sumV + maxprofit(items, w - sumW, m + 2);
            pq.push(make_pair(a, profit));
            if (w - sumW - items[m + 1].second >= 0) {
                a[m + 1] = 1;
                profit =
                    items[m + 1].first + sumV +
                    maxprofit(items, w - sumW - items[m + 1].second, m + 2);
                pq.push(make_pair(a, profit));
            }
        }
    }
}

int main() {
    int i;
    scanf("%lf%d", &w, &n);
    vector<pair<double, double>> items(n);
    for (auto& item : items) {
        scanf("%lf", &item.first);
    }
    for (auto& item : items) {
        scanf("%lf", &item.second);
    }
    sort(items.begin(), items.end(), comp);

    vmax = -1;
    knapsack(items, 0);
    printf("%.4lf", vmax);

    return 0;
}