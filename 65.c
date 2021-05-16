#include "stdbool.h"
#include "string.h"
#include "ctype.h"

bool isNumber(char * s){
    int len = strlen(s);

    if (len < 2) return isdigit(s[0]);

    int idx = 0;
    if (s[idx] == '+' || s[idx] == '-') idx++;
    bool hasE = false;
    bool valid = false;
    bool dot = false;
    while (idx < len) {
        if (isdigit(s[idx])) {
            valid = true;
        } else if (s[idx] == '.') {
            if (dot) return false;
            dot = true;
        } else if (s[idx] == 'e' || s[idx] == 'E') {
            if (!valid) return false;
            hasE = true;
            idx++;
            break;
        } else {
            return false;
        }
        
        idx++;
    }
    
    if (!hasE) return valid;

    if (s[idx] == '+' || s[idx] == '-') idx++;
    if (idx == len) return false; 

    while (idx < len) {
        if (!isdigit(s[idx])) return false;
        idx++;
    }

    return true;
}
