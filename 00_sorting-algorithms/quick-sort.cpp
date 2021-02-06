#include <vector>
#include <algorithm>

// Partition by Hoare's algorithm, O(n).
// Choose a pivot. (Can be anything except stop.) 
// Make Left side of partition <= pivot,and the right side >= pivot.   
int partition(std::vector<int> &v, int start,int stop) {
    int pivot = v[start];

    int left = start - 1;
    int right = stop + 1;
    while (left < right) {
        while(v[left] < pivot) left++;         // Check from left/right end and move in.
        while(v[right] > pivot) right--;       // If values are already on the correct side of the pivot, skip them.
        if (left < right)                      
            std::swap(v[left], v[right]);      // When we find a pair of values both on the wrong side, swap them.     
        else 
            return right;
    }
    return right;

}

// Split vector at pivot and sort recursively.
// Simply conquer by attatching the two sides together.
// All elements in left side are smaller than all elements in right side.
void sort(std::vector<int> &v, int start, int stop) {
     if(start < stop) {
         int p = partition(v,start,stop);
         sort(v,start,p);
         sort(v,p+1,stop);
     }
}

void quick_sort(std::vector<int> &A) {
    sort(A, 0, A.size());
}

/*
NOTE: This version is still buggy.

- Sometimes wrong result:

7
53 24 20 55 44 21 22 
21 22 24 44 53 0 55

7
19 26 32 56 99 91 13   
19 26 32 56 91 0 99 

- Always runs infinitely at n >= 9, and sometimes at smaller values too
- Debugger arbitrarily stops because GDC
*/