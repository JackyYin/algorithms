#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int ans = 0;
        for (int i = 0; startFuel < target;) {
            while (i < (int) stations.size() && stations[i][0] <= startFuel) {
                pq.push(stations[i++][1]);
            }
            if (pq.empty()) return -1;

            startFuel += pq.top();
            ans++;
            pq.pop();
        }
        return ans;
    }
};
