#include <iostream>
#include <vector>

void merge(std::vector<int> &v, int start, int m, int stop,
           std::vector<int> &tmp) {
    int li = start;                        // Index of left part
    int ri = m;                            // Index of right part
    for (int i = start; i < stop; i++) {   // Put result in index i.
        if (ri >= stop) {  // Case: Right is empty, so put result from Left.
            tmp[i] = v[li++];
            continue;
        }
        if (li >= m) {  // Case: Left is empty, so put result from Right.
            tmp[i] = v[ri++];
            continue;
        }
        tmp[i] = (v[li] < v[ri]) ? v[li++] : v[ri++];

    }
    // Copy result from temp vector to v.
    for (int i = start; i <= stop; i++) v[i] = tmp[i];
}

void sort(std::vector<int> &v, int start, int stop, std::vector<int> &tmp) {
    if (stop - start > 1) {  // Sort if there is more than 1 element:
        int m = (start + stop) / 2;
        sort(v, start, m, tmp);
        sort(v, m, stop, tmp);
        merge(v, start, m, stop, tmp);
    }
}

void merge_sort(std::vector<int> &A) {
    std::vector<int> B(A.size());
    sort(A, 0, A.size(), B);
}