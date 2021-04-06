#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, i, j;
    scanf("%d%d", &n, &m);
    vector<int> v(m);
    for (i = 0; i < m; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    double sum = 0;
    for (i = 0; i < n; i++) {
        int tmp = 0;
        for (j = 0; j < m; j++) {
            if (j % n == i) {
                tmp += v[j];
                sum += tmp;
            }
        }
    }
    printf("%.3lf", sum / m);
    return 0;
}