int minFlips(int a, int b, int c) {
    int xored = (a | b) ^ c;
    int anded = (a & b) & xored;

    int cnt = 0;
    while (xored) {
        xored &= (xored - 1);
        cnt++;
    }

    while (anded) {
        anded &= (anded - 1);
        cnt++;
    }

    return cnt;
}
