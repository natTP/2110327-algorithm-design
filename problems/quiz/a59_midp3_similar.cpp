#include <cstdio>
#include <cstring>

char a[131075], b[131075];

bool isSimilar(int startA, int startB, int len) {
    if (len == 1) return a[startA] == b[startB];
    len /= 2;
    return (isSimilar(startA, startB, len) &&
            isSimilar(startA + len, startB + len, len)) ||
           (isSimilar(startA, startB + len, len) &&
            isSimilar(startA + len, startB, len));
}

int main() {
    scanf("%s%s", a, b);
    printf(isSimilar(0, 0, strlen(a)) ? "YES" : "NO");
    return 0;
}