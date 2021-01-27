void recursive (int cur, int n, long* ans) {
    if (cur > n) return;

    unsigned int len = 0, cp = cur;
    for (len = 0; cp > 0; len++) {
        cp >>= 1;
    }

    *ans <<= len;
    *ans |= cur;
    *ans %= ((int)1e9 + 7);

    recursive(cur + 1, n, ans);
}

int concatenatedBinary(int n){
    long ans = 0;

    recursive(1, n, &ans);

    return ans;
}
