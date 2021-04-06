#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, l, i;
    scanf("%d%d", &n, &l);
    vector<int> v(n);
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for (i = 0; i < n; i++) {
        int current = v[i];
        cnt++;
        while ((i < n) && (v[i + 1] < current + l)) i++;
    }
    printf("%d", cnt);
    return 0;
}