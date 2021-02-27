#include <algorithm>
#include <cstdio>

void solve(int n, int k, int start, int stop) {
    // Merge count one more time -> just print as-is.
    if (k == 1) {
        for (int i = start; i <= stop; i++) printf("%d ", i);
        return;
    }
    int mid = n / 2;
    // 2*mid -1 is the max number of calls for the left subproblem.
    int newK = std::min(k - 2, 2 * mid - 1);
    // Left half
    solve(mid, newK, stop - mid + 1, stop);
    // Right half (the rest)
    solve(n - mid, k - newK - 1, start, start + (n - mid) - 1);
    // If more ks are left, this means the numbers are further from being
    // sorted. Therefore we swap stop to left side and start to right side.
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    if (k % 2 == 0 || k > 2 * n - 1) {
        printf("-1");
    } else {
        solve(n, k, 1, n);
    }
    return 0;
}