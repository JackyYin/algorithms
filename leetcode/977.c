#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int *res = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    int splitted = -1;
    // find split index
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] >= 0) {
            splitted = i;
            break;
        }
    }

    // calculate square
    for (int i = 0; i < numsSize; i++) {
        nums[i] *= nums[i];
    }

    if (splitted < 0) {
        // all negative
        for (int i = 0; i < numsSize; i++) {
            res[numsSize - 1 - i] = nums[i];
        }
    } else if (splitted == 0) {
        // all positive
        for (int i = 0; i < numsSize; i++) {
            res[i] = nums[i];
        }
    } else {
        // merge two sorted array
        int idx = 0;
        int left = splitted - 1;
        int right = splitted;

        while (left >= 0 && right < numsSize) {
            if (nums[left] <= nums[right]) {
                res[idx++] = nums[left--];
            } else if (nums[right] < nums[left]) {
                res[idx++] = nums[right++];
            }
        }

        while (left >= 0) {
            res[idx++] = nums[left--];
        }

        while (right < numsSize) {
            res[idx++] = nums[right++];
        }
    }

    return res;
}
