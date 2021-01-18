#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        //cout << "-----" << endl;
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;

        int ans = 0;
        while (left < right) {
            //cout << left << "," << right << endl;
            if (nums[left] + nums[right] == k) {
                ans++;
                left++;
                right--;
            } else if (nums[left] + nums[right] < k) {
                left++;
            } else {
                right--;
            }
        }

        return ans;
    }
};
