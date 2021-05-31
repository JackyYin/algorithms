#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> cumu;

        cumu.push_back(0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            cumu.push_back(sum);
        }

        unordered_map<int, int>m;
        int Max = 0;
        int start = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!m.count(nums[i])) {
                m[nums[i]] = i;
            } else {
                Max = max(Max, cumu[i] - cumu[start]);
                start = max(start, m[nums[i]] + 1);
                m[nums[i]] = i;
            }
        }

        return max(Max, cumu[nums.size()] - cumu[start]);
    }
};
