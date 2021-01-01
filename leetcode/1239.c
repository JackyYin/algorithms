#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX(a,b) (a > b ? a : b);

int maxLength(char ** arr, int arrSize) {
    int max = 0;

    int *dp = malloc(sizeof(int) * pow(2, arrSize));
    dp[0] = 0;
    int dpLen = 1;

    for (int i = 0; i < arrSize; i++) {
        int tmp = 0;
        for (size_t j = 0; j < strlen(arr[i]); j++) {
            tmp = tmp | (1 << (arr[i][j] - 'a'));
        }

        int tmpLen = __builtin_popcount(tmp);
        if (tmpLen < (int) strlen(arr[i])) {
            continue;
        }

        for (int k = 0; k < dpLen; k++) {
            if (dp[k] & tmp) continue;

            dp[dpLen++] = dp[k] | tmp;
            max = MAX(max, tmpLen + __builtin_popcount(dp[k]));
        }
    }
    return max;
}
