#include <bits/stdc++.h>

using namespace std;

// DFS in State Space with Backtracking
int n, cnt;

bool isValid(int col[], int m) {
    for (int r = 1; r < m; r++) {
        if (col[m] == col[r] || abs(col[m] - col[r]) == m - r) return false;
    }
    return true;
}

void queen(int col[], int m) {  // m rows have been filled
    if (m == n)
        cnt++;
    else {
        for (int i = 1; i <= n; i++) {
            col[m + 1] = i;
            if (isValid(col, m + 1)) queen(col, m + 1);
        }
    }
}

int main() {
    scanf("%d", &n);
    int col[n + 1];  // col[i] is column of queen in row i
    cnt = 0;
    queen(col, 0);
    printf("%d", cnt);
    return 0;
}