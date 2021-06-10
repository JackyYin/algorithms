#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = (int) nums.size();
        deque<int> q;

        q.push_back(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            if (q.front() > i + k) {
                q.pop_front();
            }

            int cur = nums[i] + nums[q.front()];
            while (!q.empty() && cur > nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            nums[i] = cur;
        }
        return nums[0];
    }
};
