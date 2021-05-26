#include <bits/stdc++.h>

using namespace std;

// DFS in State Space
int cnt;

// n = total value of set, i = min val of elements
void subsetSum(int n, int k) {
    if (n == 0) cnt++;
    for (int i = k; i <= n; i++) {
        subsetSum(n - i, i);
    }
}

int main() {
    int n;
    cnt = 0;
    scanf("%d", &n);
    subsetSum(n, 1);
    printf("%d", cnt);
    return 0;
}