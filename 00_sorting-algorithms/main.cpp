#include <chrono>
#include <ctime>
#include <functional>
#include <iostream>
#include <vector>

#include "sorting-algorithms.cpp"

template <typename T>
void print_vector(std::vector<T> v) {
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n\n";
}

int runtime(std::vector<int> &v, std::function<void(std::vector<int> &)> func) {
    auto start = std::chrono::high_resolution_clock::now();
    func(v);
    //std::cout << "\nHere Done\n";
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    return duration.count();
}

int main() {
    int n;
    size_t i;
    std::vector<int> A;
    std::cin >> n;

    srand(time(NULL));

    // create a vector of n random integers
    for (i = 0; i < n; i++) {
        A.push_back(rand() % 100);
    }
    // print_vector(A);

    // (1) Selection Sort
    std::vector<int> B1(A.begin(), A.end());
    std::cout << "Selection Sort: " << runtime(B1, &selection_sort) << " ms\n";

    // (2) Merge Sort
    std::vector<int> B5(A.begin(), A.end());
    std::cout << "Merge Sort: " << runtime(B5, &merge_sort) << " ms\n";
    // print_vector(B5);

    return 0;
}