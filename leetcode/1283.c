#define MIN(a,b) (a > b ? b : a);

int smallestDivisor(int* nums, int numsSize, int threshold){
    int left = 1;
    int right = 1000000;
    int ans = 1000000;

    while (left < right) {
        int mid = (left + right) / 2;

        int sum = 0;
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] % mid == 0) {
                sum += nums[i] / mid;
            } else {
                sum += nums[i] / mid + 1;
            }
        }

        if (sum > threshold) {
            left = mid + 1;
        } else {
            right = mid;
            ans = MIN(ans, mid);
        }
    }

    return ans;
}
