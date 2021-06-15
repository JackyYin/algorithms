#include <vector>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<int> bucket(1001, 0);

        for (auto &b: boxTypes) {
            bucket[b[1]] += b[0];
        }

        int sum = 0;
        for (int i = 1000; i >= 0; i--) {
            if (bucket[i] == 0) continue;

            int boxCnt = min(bucket[i], truckSize);
            sum += boxCnt * i;
            truckSize -= boxCnt;           

            if (truckSize == 0) break;
        }
        return sum;
    }
};
