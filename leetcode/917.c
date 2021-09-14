#include <ctype.h>
#include <stdint.h>
#include <string.h>

char * reverseOnlyLetters(char * s){
    uint8_t i = 0, j = strlen(s) - 1;
    char tmp;

    while (i < j) {
        if (!isalpha(s[i])) {
            i++;
            continue;
        }

        if (!isalpha(s[j])) {
            j--;
            continue;
        }

        tmp = s[i];
        s[i++] = s[j];
        s[j--] = tmp;
    }

    return s;
}
