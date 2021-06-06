#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector< pair<int, int> > ess(n);

        for (int i = 0; i < n; i++) {
            ess.push_back( make_pair(efficiency[i], speed[i]) );
            // ess[i] = {efficiency[i], speed[i]};
        }

        // sort by efficiency desc
        sort(ess.rbegin(), ess.rend());

        priority_queue< int, vector<int>, greater<int> > pq;
        long Max = 0;
        long speedSum = 0;
        for (auto& [e, s] : ess) {
            if ((int) pq.size() == k) {
                int minSpeed = pq.top();
                speedSum -= minSpeed;
                pq.pop();
            }

            pq.push(s);
            speedSum += s;
            Max = max(Max, e * speedSum);
        }

        return Max % (long)(1e9+7);
    }
};
