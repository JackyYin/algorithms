

int minOperations(int n){
    int sum = 0;
    for (int i = 0; i < (n - 1) / 2; i++) {
        sum += (i + 1) * 2;
    }

    if (n % 2 == 0) {
        sum += n / 2;
    }

    return sum;
}
