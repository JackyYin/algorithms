#include "stdbool.h"

void heapify(int *arr, int arrSize, int idx)
{
    int lcIdx = idx * 2 + 1;
    int rcIdx = idx * 2 + 2;

    int maxIdx = idx;
    if (lcIdx < arrSize && arr[lcIdx] > arr[maxIdx]) {
        maxIdx = lcIdx;
    }
    if (rcIdx < arrSize && arr[rcIdx] > arr[maxIdx]) {
        maxIdx = rcIdx;
    }

    if (maxIdx == idx) return;
    int tmp = arr[idx];
    arr[idx] = arr[maxIdx];
    arr[maxIdx] = tmp;
    heapify(arr, arrSize, maxIdx);
}

void buildHeap(int *arr, int arrSize)
{
    if (arrSize <= 3) {
        heapify(arr, arrSize, 0);
    } else {
        for (int i = (arrSize - 1) / 2; i >= 0; i--) {
            heapify(arr, arrSize, i);
        }
    }
}

bool isPossible(int* target, int targetSize){
    if (targetSize == 1 && target[0] != 1) return false;
    
    buildHeap(target, targetSize);

    long sum = 0;
    for (int i = 0; i < targetSize; i++) {
        sum += target[i];
    }

    // get max
    while (target[0] != 1) {
        sum -= target[0]; // sum of all except biggest number
        if (sum == 1) return true;
        if (sum > target[0] || target[0] % sum == 0) return false;
        target[0] %= sum;
        sum += target[0];
        heapify(target, targetSize, 0);
    }
    return true;
}
