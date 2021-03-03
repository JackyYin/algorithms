class Solution {
public:
    void recurModifyArr(vector<int>& nums, int index) {
        while (nums[index] != index && nums[index] < nums.size()) {
            swap(nums[index], nums[nums[index]]);
        }
    };

    int missingNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            recurModifyArr(nums, i);
        }

        for (int i = 0; i < nums.size(); i++) {
            //printf("%d\n", nums[i]);
            if (nums[i] != i) return i;
        }

        return nums.size();
    };
};

