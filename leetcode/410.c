#define MAX(a,b) (a > b ? a : b);

int splitArray(int* nums, int numsSize, int m){
    int left = 1;
    int right = 0;
    for (int i = 0; i < numsSize; i++) {
        left = MAX(left, nums[i]);
        right += nums[i];
    }

    while (left < right) {
        int mid = (left + right) / 2;

        int sets = 0;
        int s = 0;
        for (int i = 0; i < numsSize; i++) {
            s += nums[i];

            if (s > mid) {
                s = nums[i];
                sets++;
            }
        }
        sets++;

        if (sets > m) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}
