#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        size_t sz = cost.size();
        vector<int> dp(sz);
        
        dp[0] = 0;
        dp[1] = 0;
        
        for (int i = 2; i < (int)sz; i++) {
            dp[i] = min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2]);
        }
        
        return dp[sz - 1];
    }
};
