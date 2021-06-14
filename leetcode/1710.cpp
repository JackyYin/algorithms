#include <vector>
using namespace std;

bool mycompare(vector<int> a, vector<int> b) {
    return a[1] > b[1];
}

class Solution {
public:
    int maximumUnits(vector< vector<int> >& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), mycompare);
    
        int sum = 0;
        for (auto &v: boxTypes) {
            //cout << v[0] << " " << v[1] << endl;
            int boxCnt = min(v[0], truckSize);
            sum += boxCnt * v[1];
            truckSize -= boxCnt;           
            if (truckSize == 0) break;
        }
        
        return sum;
    }
};
