#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k, d, e, l, i;
    scanf("%d%d%d", &n, &m, &k);
    vector<pair<int, int>> day(k + 1);
    for (i = 0; i < k; i++) {
        scanf("%d%d%d", &d, &e, &l);
        day[d].first = e;
        day[d].second = l;
    }

    queue<int> qplant, qstore;
    for (i = 1; i <= k; i++) {
        if (day[i].first == 0)
            qplant.push(day[i].second);
        else if (day[i].first == 1)
            qstore.push(day[i].second);

        // If there are both requests and products
        if (qplant.size() != 0 && qstore.size() != 0) {
            if (day[i].first == 0)
                // plant sends product to waiting store
                printf("%d\n", qstore.front());
            else if (day[i].first == 1)
                // store receives product from waiting plant
                printf("%d\n", qplant.front());
            // both plant and store are removed from queue
            qstore.pop();
            qplant.pop();
        } else
            printf("0\n");
    }
    return 0;
}