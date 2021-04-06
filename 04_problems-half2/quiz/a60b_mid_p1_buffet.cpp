#include <bits/stdc++.h>

using namespace std;

int main() {
    int f, w, n, i;
    scanf("%d%d%d", &f, &w, &n);
    vector<int> v(f);
    for (i = 0; i < f; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for (i = 0; i < f; i++) {
        int current = v[i];
        cnt++;
        while ((i < f) && (v[i + 1] <= current + w + w)) i++;
    }
    printf("%d", cnt);
    return 0;
}