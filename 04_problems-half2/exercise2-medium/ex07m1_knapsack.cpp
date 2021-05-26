#include <bits/stdc++.h>

using namespace std;

// DFS in State Space with Backtracking
int n;
double vmax, w;

double sum(vector<double> a, vector<int> b, int m) {
    double ans = 0;
    for (int i = 0; i < m; i++) ans += a[i] * b[i];
    return ans;
}

void knapsack(vector<double>& weight, vector<double>& val, vector<int>& ans,
              int m) {
    if (sum(weight, ans, m) > w) return;
    if (m == n) {
        double v = sum(val, ans, m);
        if (v > vmax) {
            vmax = v;
        }
    } else {
        ans[m + 1] = 1;
        knapsack(weight, val, ans, m + 1);
        ans[m + 1] = 0;
        knapsack(weight, val, ans, m + 1);
    }
}

int main() {
    int i;
    scanf("%lf%d", &w, &n);
    vector<double> val(n + 1);
    vector<double> weight(n + 1);
    vector<int> ans(n + 1);
    for (i = 0; i < n; i++) {
        scanf("%lf", &val[i]);
    }
    for (i = 0; i < n; i++) {
        scanf("%lf", &weight[i]);
    }

    vmax = -1;
    for (i = 0; i < n; i++) ans[i] = 0;
    knapsack(weight, val, ans, 0);
    printf("%.4lf", vmax);

    return 0;
}