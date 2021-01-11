#include <string.h>

#include <string.h>

#define MIN(a,b) (a > b ? b : a)
int c[100001];
static inline int get (int x) {
    int sum = 0;
    while (x > 0) {
        sum += c[x];
        x -= x & -x;
    }
    return sum;
}

static inline void update (int x) {
    while (x <= 100000) {
        c[x] += 1;
        x += x & -x;
    }
}

int createSortedArray(int* instructions, int instructionsSize){
    memset(&c, 0, sizeof(int) * 100001);
    int res = 0;
    int module = 1e9 + 7;

    for (int i = 0; i < instructionsSize; i++) {
        res = (res + MIN(get(instructions[i] - 1), i - get(instructions[i]))) % module;
        update(instructions[i]);
    }

    return res;
}
