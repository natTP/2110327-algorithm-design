#include <cstdio>

typedef long long ll;

int main() {
    ll n, i, j;
    scanf("%lld", &n);
    ll a[3], tmp[3];
    a[0] = 3;
    a[1] = 2;
    a[2] = 2;
    for (i = 4; i <= n; i++) {
        for (j = 0; j < 3; j++) tmp[j] = a[j];
        a[0] = (tmp[0] % 100000007 + tmp[1] % 100000007) % 100000007;
        a[1] = (tmp[1] % 100000007 + tmp[2] % 100000007) % 100000007;
        a[2] = tmp[0] % 100000007;
    }
    printf("%lld", (a[0] + a[1] + a[2]) % 100000007);
    return 0;
}