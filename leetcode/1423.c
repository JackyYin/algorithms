#define MAX(a,b) (((a) > (b)) ? (a) : (b))

int maxScore(int* cardPoints, int cardPointsSize, int k){
    int cumulativeFront[k + 1];
    int cumulativeBack[k + 1];
    cumulativeFront[0] = 0;
    cumulativeBack[0] = 0;

    int curSum = 0;
    for (int i = 0; i < k; i++) {
        curSum += cardPoints[i];
        cumulativeFront[i + 1] = curSum;
    }
    curSum = 0;
    for (int i = 0; i < k; i++) {
        curSum += cardPoints[cardPointsSize - 1 - i];
        cumulativeBack[i + 1] = curSum;
    }

    int max = 0;
    for (int i = 0; i <= k; i++) {
        max = MAX(max, cumulativeFront[i] + cumulativeBack[k - i]);
    }

    return max;
}

/* int maxScore(int* cardPoints, int cardPointsSize, int k){ */
/*     int max = 0; */
/*     for (int i = 0; i <= k; i++) { */
/*         int score = 0; */
/*         for (int j = 0; j < i; j++) { */
/*             score += cardPoints[j]; */
/*         } */
/*         for (int j = 0; j < k - i; j++) { */
/*             score += cardPoints[cardPointsSize - 1 - j]; */
/*         } */

/*         max = MAX(max, score); */
/*     } */

/*     return max; */
/* } */
