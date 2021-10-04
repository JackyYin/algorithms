class Solution {
public:
    bool search(vector<bool> &dp, vector<int> &nums, int idx) {
        if (idx + nums[idx] >= nums.size() - 1) return true;
        if (nums[idx] == 0) return false;
        for (int i = idx + 1; i <= idx + nums[idx]; i++) {
            if (dp[i]) {
                if (search(dp, nums, i)) {
                    return true;
                } else {
                    dp[i] = false;
                }
            }
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), true);
        return search(dp, nums, 0);
    }
};
