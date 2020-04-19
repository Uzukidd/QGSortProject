#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include "../inc/qgsort.h"

using namespace std;

void insertSort(int *a,int n) {

    for(int i = 0;i < n;i++) {

        int ptr = i;

        for(int j = i - 1;j >= 0;j--) {

            if(a[ptr] < a[j]) {

                swap(a[ptr], a[j]);

                ptr--;

            } else {

                break;

            }

        }
        
    }

}

void MergeArray(int *a,int begin,int mid,int end,int *temp) {

    if(begin + 2 == end) { //When the scale has shrunk to a small-scale

        int temp = min(a[begin], a[begin + 1]);

        a[begin + 1] = max(a[begin], a[begin + 1]);

        a[begin] = temp;
        
        return;

    }

    int left = mid - begin, right = end - mid;

    int step_l = 0, step_r = 0;

    // Dividing two arrays like dividing two sets of cards

    // From Introduction to Algorithm

    for(int i = begin;i < mid;i++) temp[i] = a[i];

    for(int i = mid;i < end;i++) temp[i] = a[i];


    

    while(step_l + step_r < end - begin) {

        if(temp[step_l + begin] < temp[step_r + mid] && step_l < left || step_r >= right) {

            a[step_l + step_r + begin] = temp[step_l + begin];

            step_l++;

        } else if(step_r < right || step_l >= left){

            a[step_l + step_r + begin] = temp[step_r + mid];

            step_r++;

        }

    }

}

// [begin, end) mode we use in the all following sort index system

void MergeSort(int *a,int begin,int end,int *temp) {

    if(begin + 1 >= end) return;

    MergeSort(a, begin, (begin + end) / 2, temp);

    MergeSort(a, (begin + end) / 2, end, temp);

    MergeArray(a, begin, (begin + end) / 2, end, temp);

}

void QuickSort_Recursion(int *a, int begin, int end) {

    if(begin + 1 >= end) return; //When a remain's elements has reached one

    if(begin + 2 >= end) { //When the scale has shrunk to a small-scale

        int temp = min(a[begin], a[begin + 1]);

        a[begin + 1] = max(a[begin], a[begin + 1]);

        a[begin] = temp;
        
        return;

    }

    int pivot = Partition(a, begin, end);

    QuickSort_Recursion(a, begin, pivot);

    QuickSort_Recursion(a, pivot + 1, end);

}

// Iteraiton version

void QuickSort(int *a,int size) {

    int begin = 0, end = size;
    
    int pivot;

    queue<pair<int,int>> q;

    q.emplace(0, size);

    // The same as the recursion version

    while(!q.empty()) {

        begin = q.front().first;

        end = q.front().second;

        q.pop();

        if(begin + 1 >= end) continue;

        if(begin + 2 >= end) {

            int temp = min(a[begin], a[begin + 1]);

            a[begin + 1] = max(a[begin], a[begin + 1]);

            a[begin] = temp;
            
            continue;

        }

        pivot = Partition(a, begin, end);

        q.emplace(begin, pivot);

        q.emplace(pivot + 1, end);

    }

}

int Partition(int *a, int begin, int end) {

    //Select the begining number as the pivot constantly

    int pivot = a[begin], ptr1 = begin, ptr2 = end - 1;

	while(ptr1 < ptr2) {
        
        while(ptr1 < ptr2 && a[ptr2] >= pivot) {

            ptr2--;

        }

        a[ptr1] = a[ptr2];

        while(ptr1 < ptr2 && a[ptr1] <= pivot) {

            ptr1++;

        }

        a[ptr2] = a[ptr1];

    }

    a[ptr1] = pivot;

    return ptr1;

}

void CountSort(int *a, int size, int max) {

    int *count = new int[max + 1];

    int ptr = 0;

    memset(count, 0, (max + 1) * sizeof(int));

    for(int i = 0;i < size;i++) {
    
        count[a[i]]++;

    }

    for(int i = 0;i <= max && ptr < size;i++) {

        while(count[i]-- > 0) {

            a[ptr++] = i;

        }

    }

    delete[] count;

}

void RadixCountSort(int *a,int size) {

    queue<int> **count = new queue<int>*[10];

    for(int i = 0;i < 10;i++) count[i] = new queue<int>();

    int ptr = 0, digit = 1;

    bool checking = 1;

    for(int d = 0;d <= digit;d++) {

        for(int i = 0;i < size;i++) {

            if(checking) digit = max(digit, (int)(log10(a[i]) + 0.000001));

            int temp = (int)(a[i] / (pow(10, d) + 0.00001)) % 10;

            count[temp] -> push(a[i]);

        }

        for(int i = ptr = 0;i < 10;i++) {

            while(!count[i] -> empty()) {

                a[ptr++] = count[i] -> front();

                count[i] -> pop();

            }

        }

        checking = 0;

    }

    for(int i = 0;i < 10;i++) delete count[i];

    delete[] count;

}

void ColorSort(int *a, int size) {

    int ptr1 = 0, ptr2 = size - 1, ptr0 = 0;

    while(ptr0 <= ptr2) {

        if(a[ptr0] == 0) {

            swap(a[ptr0++], a[ptr1++]);

        } else if(a[ptr0] == 2) {

            swap(a[ptr0], a[ptr2--]);

        } else if(a[ptr0] == 1) ptr0++;
        
    }
    

}

int findNoKElements(int *a, int begin, int end, int K) {

    int pivot = Partition(a, begin, end);

    if(pivot > K) return findNoKElements(a, 0, pivot, K);

    else if(pivot < K) return findNoKElements(a, pivot + 1, end, K);

    else return a[pivot];

}