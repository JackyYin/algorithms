#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deset;
        unordered_set<string> visited;
        for (string& deadend : deadends) {
            deset.insert(deadend);
        }

        if (deset.count("0000") > 0) return -1;

        queue<string> q;
        q.push("0000");
        visited.insert("0000");

        int layer = 0;
        while (!q.empty()) {
            size_t nodeCnt = q.size();
            while (nodeCnt-- > 0) {
                string cur = q.front();
                if (cur == target) return layer;

                for (int i = 0; i < 4; i++) {
                    string tmp = cur;
                    tmp[i] = cur[i] == '9' ? '0' : cur[i] + 1;
                    if (deset.count(tmp) == 0 && visited.count(tmp) == 0) {
                        q.push(tmp);
                        visited.insert(tmp);
                    }
                    tmp[i] = cur[i] == '0' ? '9' : cur[i] - 1;
                    if (deset.count(tmp) == 0 && visited.count(tmp) == 0) {
                        q.push(tmp);
                        visited.insert(tmp);
                    }
                }

                q.pop();
            }
            layer++;
        }
        return -1;
    }
};
