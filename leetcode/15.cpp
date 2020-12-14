#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = (int) nums.size();
        vector<vector<int>> res;

        if (len < 3) return res;

        // maybe take O(nlogn)
        sort(nums.begin(), nums.end());

        int i = 0;
        while (i < len - 2) {
            int target = 0 - nums[i];

            // two sum of sorted array
            int left = i + 1;
            int right = len - 1;
            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    res.push_back(vector<int>{ nums[i], nums[left], nums[right] });

                    while (left < len - 1 && nums[left] == nums[left + 1]) left++;
                    left++;

                    while (right > 0 && nums[right] == nums[right - 1]) right--;
                    right--;
                } else if (nums[left] + nums[right] > target) {
                    while (right > 0 && nums[right] == nums[right - 1]) right--;
                    right--;
                } else if (nums[left] + nums[right] < target) {
                    while (left < len - 1 && nums[left] == nums[left + 1]) left++;
                    left++;
                }
            }

            while (i < len - 1 && nums[i] == nums[i + 1]) i++;
            i++;
        }

        return res;
    }
};

