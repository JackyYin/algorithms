#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> wmasks;
        
        for (auto word : words) {
            int mask = 0;
            for (char c : word) {
                mask |= (1 << (c - 'a'));
            }
            wmasks.push_back(mask);
        }
        
        int res = 0;
        for (int i  = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (!(wmasks[i] & wmasks[j])) {
                    int product = words[i].length() * words[j].length();
                    res = max(res, product);
                }
            }
        }
        
        return res;
    }
};
