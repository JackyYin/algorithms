#include <string>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int max = 0;
        for (char c : n) {
            if (c - '0' > max) max = c - '0';
        }
        
        return max;
    }
};
