#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

bool isValid(vector<int> &v, int start, int end) {
    if (end - start == 2) {
        return !v[start] && v[end - 1];
    }
    int mid = (start + end) / 2;
    bool b = isValid(v, mid, end);
    bool a1 = isValid(v, start, mid);
    reverse(v.begin() + start, v.begin() + mid);
    bool a2 = isValid(v, start, mid);
    reverse(v.begin() + start, v.begin() + mid);
    return b && (a1 || a2);
}

int main() {
    int n, k, i;
    scanf("%d%d", &n, &k);
    int len = 1 << k;
    vector<int> virus(len), reverse(len);
    while (n--) {
        for (i = 0; i < len; i++) {
            scanf("%d", &virus[i]);
            reverse[len - i - 1] = virus[i];
        }
        printf(isValid(virus, 0, len) ? "yes\n" : "no\n");
    }
    return 0;
}