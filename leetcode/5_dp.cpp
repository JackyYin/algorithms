#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp (s.size(), vector<bool>(s.size(), false));

        int start = 0;
        int maxlen = 1;

        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = true;
        }

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                start = i;
                maxlen = 2;
            }
        }

        int len = 3;
        while (len <= s.size()) {
            for (int i = 0; i <= s.size() - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                     dp[i][j] = true;
                    start = i;
                    maxlen = len;
                }
            }
            len++;
        }

        return s.substr(start, maxlen);
    }
};

