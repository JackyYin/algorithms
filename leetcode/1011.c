int shipWithinDays(int* weights, int weightsSize, int D){
    //printf("------\n");
    int left = 1;
    int right = 500 * weightsSize;

    while (left < right) {
        int mid = (left + right) / 2;

        int days = 0;
        int sum = 0;
        for (int i = 0; i < weightsSize; i++) {
            if (weights[i] > mid) {
                days = 50000;
                break;
            }

            sum += weights[i];
            if (sum > mid) {
                sum = weights[i];
                days++;
            }
        }
        days++;
        //printf("%d %d\n", mid, days);

        if (days > D) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}
