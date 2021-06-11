#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;

        // prepare index 0 to previous index of k
        for (int i = 0; i < k - 1; i++) {
            while (!q.empty() && nums[i] > nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        vector<int> res;
        // prepare index k to last index
        for (int i = k - 1; i < nums.size(); i++) {
            while (!q.empty() && nums[i] > nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            res.push_back(nums[q.front()]);
            if (q.front() <= i - k + 1) {
                q.pop_front();
            }
        }
        return res;
    }
};
