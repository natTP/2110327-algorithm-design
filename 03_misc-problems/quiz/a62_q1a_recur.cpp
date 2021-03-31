#include <cstdio>

int v[260][260];

void fill(int a, int b, int top, int bottom, int left, int right) {
    if (a == 0)
        v[top][left] = b;
    else {
        int newSize = 1 << (a - 1);
        fill(a - 1, b, top, bottom - newSize, left, right - newSize);
        fill(a - 1, b - 1, top, bottom - newSize, left + newSize, right);
        fill(a - 1, b + 1, top + newSize, bottom, left, right - newSize);
        fill(a - 1, b, top + newSize, bottom, left + newSize, right);
    }
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int size = 1 << a;
    fill(a, b, 0, size, 0, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
    return 0;
}