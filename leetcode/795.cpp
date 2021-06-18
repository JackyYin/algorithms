#include <vector>
using namespace std;

class Solution {
private:
    vector<int> arr;
    int l;
    int r;
public:
    void findSubarray(int idx, int curMax, int& ans) {
        if (idx == arr.size()) return;

        if (arr[idx] > r) return;
        
        if (arr[idx] >= l) {
            curMax = max(curMax, arr[idx]);
            ans++;
            findSubarray(idx + 1, curMax, ans);
        } else {
            if (curMax >= l) ans++;
            curMax = max(curMax, arr[idx]);
            findSubarray(idx + 1, curMax, ans);
        }
    }
 
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        arr = nums;
        l = left;
        r = right;

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            findSubarray(i, -1, ans);
        }
        return ans;
    }
};
