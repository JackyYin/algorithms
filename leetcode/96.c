int countTree(int n, int *dp) {
    if (n == 0 || n == 1) return 1;
    if (dp[n] > 0) return dp[n];

    int s = 0;

    // choose root
    for (int i = 1; i <= n; i++) {
        s += countTree(i - 1, dp) * countTree(n - i, dp);
    }

    dp[n] = s;
    return s;
}


int numTrees(int n) {
    int dp[20] = { -1 };
    return countTree(n, dp);
}
