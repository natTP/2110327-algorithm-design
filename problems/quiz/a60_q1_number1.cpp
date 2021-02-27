#include <cstdio>

typedef long long ll;
ll ans;

void count(ll n, ll l, ll r, ll start, ll stop) {
    if (start > r || stop < l || n == 0) return;
    // Count only if the position is in range
    if (n == 1) {
        ans++;
        return;
    }
    ll mid = (start + stop) / 2;
    count(n / 2, l, r, start, mid - 1);
    count(n % 2, l, r, mid, mid);
    count(n / 2, l, r, mid + 1, stop);
}

int main() {
    ll n, l, r;
    ans = 0;
    scanf("%lld%lld%lld", &n, &l, &r);
    ll len = 1, i = n;
    while (i > 1) {
        len = 2 * len + 1;
        i /= 2;
    }
    count(n, l, r, 1, len);
    printf("%lld", ans);
    return 0;
}