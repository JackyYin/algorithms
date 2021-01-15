#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void generateStr (string s, int left, int right, int len, vector<string>& ans) {
        if (s.length() == len * 2) {
            ans.push_back(s);
            return;
        }

        if (left < len) {
            generateStr(s + "(", left + 1, right, len, ans);
        }

        if (right < left) {
            generateStr(s + ")", left, right + 1, len, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        generateStr("", 0, 0, n, ans);

        return ans;
    }
};
