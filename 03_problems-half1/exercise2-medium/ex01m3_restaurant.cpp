#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

ULL gcd(ULL a, ULL b) {
    ULL c;
    while (a % b != 0) {
        c = b;
        b = a % b;
        a = c;
    }
    return b;
}

ULL lcm(ULL a, ULL b) { return (a * b) / gcd(a, b); }

// Convert from time to index of possible times.
// Possible times have index from 1 to cperround.
// If many indices have same times, will return highest index.
ULL findIndex(vector<ULL> &v, ULL time) {
    ULL idx = 0;
    for (ULL i = 0; i < v.size(); i++) {
        idx += time / v[i];
    }
    return idx;
}

// Search this user's time.
// k - index | l,r - time | so we convert time to index before comparing with k
// Possible times are between 0 and roundlen.
ULL search(vector<ULL> &v, ULL k, ULL l, ULL r) {
    if (l >= r) return l;
    ULL mid = (l + r) / 2;
    ULL idx = findIndex(v, mid);
    if (k <= idx)
        return search(v, k, l, mid);
    else
        return search(v, k, mid + 1, r);
}

int main() {
    ULL n, a, i;
    scanf("%d%d", &n, &a);
    vector<ULL> t(n);
    ULL roundlen = 1, cperround = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &t[i]);
        roundlen = lcm(roundlen, t[i]);
    }
    for (i = 0; i < n; i++) {
        cperround += roundlen / t[i];
    }

    ULL c;
    while (a--) {
        scanf("%llu", &c);
        if (c > n) {
            ULL rounds = (c - n) / cperround;
            printf("%llu\n", search(t, (c - n) % cperround, 0, roundlen) +
                                 rounds * roundlen);
        } else {
            printf("0\n");
        }
    }
    return 0;
}