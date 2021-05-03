#include <ctype.h>

int map[26] = {
    1, 0, 0, 0, 1,
    0, 0, 0, 1, 0,
    0, 0, 0, 0, 1,
    0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0
};

bool halvesAreAlike(char * s){
    size_t len = strlen(s);

    int counter = 0;
    for (int i = 0; i < len / 2; i++) {
        counter += map[tolower(s[i]) - 'a'];
    }

    for (int i = 0; i < len / 2; i++) {
        counter -= map[tolower(s[(len / 2) + i]) - 'a'];
    }

    return counter == 0;
}
