#include <ctype.h>
#include <limits.h>

int myAtoi(char * s){
    int sign = 1;
    int num = 0;
    int idx = 0;

    while (s[idx] == ' ') {
        idx++;
    };

    if (s[idx] == '-' || s[idx] == '+') {
        sign = 1 - 2 * (s[idx++] == '-');
    }

    while (isdigit(s[idx])) {
        if (sign * num > INT_MAX / 10 || (sign * num == INT_MAX / 10 && s[idx] - '0' > 7)) return INT_MAX;
        if (sign * num < INT_MIN / 10 || (sign * num == INT_MIN / 10 && s[idx] - '0' > 7)) return INT_MIN;
        num = 10 * num + (s[idx++] - '0');
    }

    return sign * num;
}
