#define MIN(a,b) (a > b ? b : a);

int minDays(int* bloomDay, int bloomDaySize, int m, int k){
    if (m * k > bloomDaySize) return -1;

    int left = 0;
    int right = 1000000000;
    int ans = -1;

    while (left < right) {
        int mid = (left + right) / 2;
        int flowers = 0;
        int bouquets = 0;

        for (int i = 0; i < bloomDaySize; i++) {
            if (bloomDay[i] > mid) {
                flowers = 0;
            } else if (++flowers == k) {
                bouquets++;
                flowers = 0;
            }
        }

        if (bouquets >= m) {
            right = mid;
            ans = MIN(ans, mid);
        } else {
            left = mid + 1;
        }
    }

    return ans;
}
