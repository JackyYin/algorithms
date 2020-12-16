#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int m = 0;
        int cur = 0;
        for (int i = 0; i < k; i++) {
            cur += nums[i];
        }
        m = cur;

        size_t idx = 1;
        while (idx < nums.size() - k + 1) {
            cur = cur + nums[idx + k - 1] - nums[idx - 1];
            m = max(m, cur);
        }

        return m / k;
    }
};
