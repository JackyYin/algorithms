#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map< string, int > dp;
    int myMax = 0;

    void memorialization(string target) {
        int len = target.length();
        int curMax = 0;
        for (int i = 0; i < len; i++) {
            string p = target.substr(0, i) + target.substr(i + 1);
            if (dp.count(p) > 0) {
                curMax = max(curMax, dp[p]);
            }
        }
        dp[target] = curMax + 1;
        myMax = max(myMax, curMax + 1);
    }
public:
    static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);

        for (string w : words) {
            memorialization(w);
        }

        return myMax;
    }
};
