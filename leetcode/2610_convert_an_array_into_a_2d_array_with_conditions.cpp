class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<vector<int>> ans;
        for (auto n : nums) {
            freq[n]++;
        }
        
        while (1) {
            vector<int> row;
            for (auto &f : freq) {
                if (f.second > 0) {
                    f.second--;
                    row.push_back(f.first);
                }
            }

            if (!row.size())
                break;
            ans.push_back(row);
        }
        return ans;
    }
};
