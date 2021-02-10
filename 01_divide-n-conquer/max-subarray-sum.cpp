#include <bits/stdc++.h>

// Returns sum of a[i...j].
int get_sum(std::vector<int> &s, int i, int j) { return s[j] - s[i - 1]; }

// O(nlogn)
int mss(std::vector<int> &a, int start, int stop, std::vector<int> &s) {
    if (start == stop) return a[start];
    int m = (start + stop) / 2;

    int r1 = mss(a, start, m, s);
    int r2 = mss(a, m + 1, stop, s);

    // B[i][j] is the sum of values from index i to j.
    // Find max of B[start...m][m].
    int maxsum_left = get_sum(s, m, m);
    for (int i = start; i <= m - 1; i++)
        maxsum_left = std::max(maxsum_left, get_sum(s, i, m));
    // Find max of B[m+1...stop][stop].
    int maxsum_right = get_sum(s, m + 1, m + 1);
    for (int i = m + 2; i <= stop; i++)
        maxsum_right = std::max(maxsum_right, get_sum(s, m + 1, i));

    int r3 = maxsum_left + maxsum_right;

    return std::max(std::max(r1, r2), r3);
}

int main() {
    int n, i;
    scanf("%d", &n);
    std::vector<int> a(n), s(n + 1);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    // Create a prefix sum array; each value is the sum from first element to i.
    s[0] = 0;
    for (i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    printf("%d", mss(a, 0, n - 1, s));
    return 0;
}