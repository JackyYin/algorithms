#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        string p = normalization(pattern);

        for (auto word : words) {
            if (normalization(word) == p) res.push_back(word);
        }
        return res;
    }

    string normalization(string word) {
        unordered_map<char, int> m;
        int cnt = 0;

        for (char c : word) {
            if (!m.count(c)) m[c] = cnt++;
        }

        string s = "";
        for (char c : word) {
            s += 'a' + m[c];
        }

        return s;
    }
};
