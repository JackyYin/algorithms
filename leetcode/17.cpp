#include <vector>
#include <string>
#include <deque>
#include <unordered_map>
using namespace std;

class Solution {
private:
    vector<string> m = {
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() < 1) return vector<string>{};
        deque<string> q;
        q.push_back("");

        for (size_t i = 0; i < digits.size(); i++) {
            string str = m[digits[i] - '2'];
            
            deque<string> q2;
            while (!q.empty()) {
                string cur = q.front();
                q.pop_front();

                for (size_t i = 0; i < str.size(); i++) {
                    q2.push_back(cur + str[i]);
                }
            }
            q = q2;
        }

        return vector<string>(q.begin(), q.end());
    }
};
