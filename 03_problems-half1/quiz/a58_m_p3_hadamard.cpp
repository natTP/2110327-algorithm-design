#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& v, queue<int>& ans, int n) {
    int i;
    vector<int> a(n);
    for (i = 0; i < n; i++) {
        a[i] = ans.front();
        ans.pop();
    }
    for (i = 0; i < n / 2; i++) {
        ans.push(a[i] + a[i + n / 2]);
    }
    for (i = 0; i < n / 2; i++) {
        ans.push(a[i] - a[i + n / 2]);
    }
}

void hadamard(vector<int>& v, queue<int>& ans, int n, int start, int stop) {
    if (n == 2) {
        ans.push(v[start] + v[stop - 1]);
        ans.push(v[start] - v[stop - 1]);
    }
    int mid = (start + stop) / 2;
    hadamard(v, ans, n / 2, start, mid);
    hadamard(v, ans, n / 2, mid, stop);
    merge(v, ans, n);
}

// nothing is printed

int main() {
    int n, i, tmp;
    scanf("%d", &n);
    vector<int> v;
    queue<int> ans;
    for (i = 0; i < n; i++) {
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
    hadamard(v, ans, n, 0, n);
    while (!ans.empty()) {
        printf("%d ", ans.front());
        ans.pop();
    }
    return 0;
}