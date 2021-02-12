#include <bits/stdc++.h>

using namespace std;

int best(int* c, int end, bool b) {
}  // ans from c[1..x], b tells whether c[x] is selected
// best(c,x,true) = max(best(c,x-1,true), best(c,x-1,false) + c[x])
// best(c,x,false) = max(best(c,x-1,true), best(c,x-1,false))

// best(c,1,true) = c[1]
// best(c,1,false) = 0

// try bottom up

int main() {
    int n, i;
    int c[n];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    return 0;
}