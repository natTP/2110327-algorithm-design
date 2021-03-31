#include <bits/stdc++.h>

using namespace std;

int merge(std::vector<int> &v, int start, int m, int stop,
          std::vector<int> &tmp) {
    int i = start;
    int j = m;
    int k = start;
    int cnt = 0;
    while ((i < m) && (j < stop)) {
        if (v[i] <= v[j]) {  // Not inversion
            tmp[k++] = v[i++];
        } else {  // Inversion
            tmp[k++] = v[j++];
            cnt += (m - i);
        }
    }
    while (i < m) {
        tmp[k++] = v[i++];
    }
    while (j < stop) {
        tmp[k++] = v[j++];
    }
    for (i = start; i < stop; i++) v[i] = tmp[i];
    return cnt;
}

int inversion(std::vector<int> &v, int start, int stop, std::vector<int> &tmp) {
    int cnt = 0;
    if (stop - start > 1) {
        int m = (start + stop) / 2;
        cnt += inversion(v, start, m, tmp);
        cnt += inversion(v, m, stop, tmp);
        cnt += merge(v, start, m, stop, tmp);
    }
    return cnt;
}

int main() {
    int n, i, tmp;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("%d", inversion(a, 0, n, b));
    return 0;
}