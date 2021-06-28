#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        int top = -1;
 
        for (auto &c : s) {
            if (top >= 0 && s[top] == c) {
                top--;
            } else {
                s[++top] = c;
            }
        }

        return s.substr(0, top + 1);
    }
};
