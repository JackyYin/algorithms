#include <vector>
#include <stack>

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::map<int, int> gtmap;
        std::stack<int> stk;
        for (atuo &n : nums2) {
            while (!stk.empty() && n > stk.top()) {
                gtmap.insert({stk.top(), n});
                stk.pop();
            }
            stk.push(n);
        }

        vector<int> res;
        for (atuo &n : nums1) {
            res.push_back(gtmap.count(n) ? gtmap[n] : -1);
        }
        return res;
    }
};
