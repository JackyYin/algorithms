#include "stdio.h"

bool isAlienSorted(char ** words, int wordsSize, char * order){
    if (wordsSize == 1) return true;

    int map[26];
    for (int i = 0; i < 26; i++) {
        map[order[i] - 'a'] = i + 1;
    }

    int strIdx, prevScore, curScore;
    for (int i = 0; i < wordsSize - 1; i++) {
        strIdx = 0;

        while (strIdx < 100) {
            prevScore = strlen(words[i]) >= strIdx + 1 ? map[words[i][strIdx] - 'a'] : 0;
            curScore = strlen(words[i + 1]) >= strIdx + 1 ? map[words[i + 1][strIdx] - 'a'] : 0;

            if (prevScore > curScore) return false;
            if (prevScore < curScore) break;
            if (prevScore == 100 && curScore == 100) break;
            strIdx++;
        }
    }

    return true;
}
