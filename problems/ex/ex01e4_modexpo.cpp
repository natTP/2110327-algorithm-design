#include <bits/stdc++.h>

int mod_expo(int x, int n, int k) {
    if (n == 1) return x % k;

    int tmp = mod_expo(x, n/2, k);
    tmp =  (tmp * tmp) % k;

    if (n % 2 == 0) return tmp;
    else return (tmp * (x % k)) % k;
}

int main() {
    int x, n, k;
    scanf("%d%d%d", &x, &n, &k);
    printf("%d", mod_expo(x,n,k));
}