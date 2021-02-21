#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // from ascii code 65 to 122
        vector<int> map (58, 0);

        // put each occurance in map
        for (auto c : t) {
            map[c - 'A']++;
        }

        int begin = 0, head = 0, counter = t.size(), d = INT_MAX;

        for (int i = 0; i < s.size(); i++) {
            if (map[s[i] - 'A']-- > 0) {
                counter--;
            }
            while(counter == 0) {
                if (i - begin + 1 < d) d = i - (head = begin) + 1;
                if (map[s[begin++] - 'A']++ == 0) counter++;
            }
        }

        return d == INT_MAX ? "" : s.substr(head, d);
    }
};
