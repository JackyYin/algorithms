void swap(int *nums, int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

int firstMissingPositive(int* nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++) {
        while (nums[i] > 0 && nums[i] <= numsSize && (nums[i] != nums[nums[i] - 1])) {
            swap(nums, i, nums[i] - 1);
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    return numsSize + 1;
}

int main ()
{
    int arr[4] = { 3, 4, -1, 1};
    firstMissingPositive(arr, 4);


    int arr2[3] = { 1, 2, 0 };
    firstMissingPositive(arr2, 3);

}
