#include <bits/stdc++.h>

int bsearch(std::vector<int> &v, int k, int start, int stop) {
    // Base Case: 1 Element.
    if (start == stop) {
        return v[start] == k ? start : -1;
    }
    // Case: More than 1 element. Find the middle value.
    int m = (start + stop) / 2;
    if (v[m] >= k)
        return bsearch(v, k, start, m);  // If k is less than middle value, then
                                         // we have to look in the left part!
    else
        return bsearch(v, k, m + 1, stop);  // Else, look right.
}

int main() {
    int n, i, k;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    std::sort(a.begin(), a.end());
    scanf("%d", &k);
    printf("%d found at %d", k, bsearch(a, k, 0, n - 1));
    return 0;
}