#include <algorithm>
#include <vector>

void selection_sort(std::vector<int> &A) {
    // Maintain a unsorted and sorted portion in A.
    // pos is the last unsorted element.
    for (size_t pos = A.size() - 1; pos > 0; pos--) {
        int max_i = 0;
        for (size_t i = 0; i <= pos; i++) {
            if (A[i] > A[max_i]) {
                max_i = i;
            }
        }
        // Select max unsorted element, and place at pos.
        std::swap(A[pos], A[max_i]);
    }
}