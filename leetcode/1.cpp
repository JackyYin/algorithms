#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> leftIdxMap;
        vector<int> ans;
        for (size_t i = 0; i < nums.size(); i++) {
            int left = target - nums[i];

            if (leftIdxMap.count(left) > 0) {
                ans.push_back(leftIdxMap[left]);
                ans.push_back(i);
            } else {
                leftIdxMap[nums[i]] = i;
            }
        }

        return ans;
    }
};
