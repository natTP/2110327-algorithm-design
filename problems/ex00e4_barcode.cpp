#include <bits/stdc++.h>

void gen_barcode(char* str, int i, int white, int black) {
    if (white == 0 && black == 0) {
        printf("%s\n", str);
    }
    if (white > 0) {  // case: let first bar be white
        str[i] = '1';
        gen_barcode(str, i + 1, white - 1, black);
    }
    if (black > 0) {  // case: let first bar be black
        str[i] = '0';
        gen_barcode(str, i + 1, white, black - 1);
    }
}

int main() {
    int A, B;
    scanf("%d%d", &A, &B);
    char str[B + 1];
    str[B] = 0;
    gen_barcode(str, 0, A, B - A);
    return 0;
}