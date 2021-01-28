void swap (int* nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void partition (int* nums, int left, int right, int *divide){
    int pivot = nums[right];
    int j = left;
    for (int i = left; i < right; i++) {
        if (nums[i] < pivot) {
            swap(nums, i, j++);
        }
    }
    swap(nums, j, right);

    *divide = j;
}

int findKthLargest(int* nums, int numsSize, int k){
    k = numsSize - k;
    int left = 0;
    int right = numsSize - 1;

    int pos;

    while (left < right) {
        partition(nums, left, right, &pos);

        if (pos > k) {
            right = pos - 1;
        } else if (pos < k) {
            left = pos + 1;
        } else {
            return nums[pos];
        }
    }
    return nums[right];
}
