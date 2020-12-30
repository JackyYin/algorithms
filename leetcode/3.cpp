#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;

        int res = 0;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (m.count(s[i]) > 0) {
                j = max(j, m[s[i]] + 1);
            }
            m[s[i]] = i;
            res = max(res, i - j + 1);
        }

        return res;
    }
};
