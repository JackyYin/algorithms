#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        // find ceil of y index
        int i = 0;
        for (; i < m; i++) {
            if (matrix[i][0] == target) return true;
            if (matrix[i][0] > target) break;
        }

        if (i == 0) return false;
        i--;

        // find ceil of x index
        int j = 0;
        for (; j < n; j++) {
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] > target) break;
        }

        while (i >= 0 && j < n) {
            if (matrix[i][j] > target) {
                i--;
            } else if (matrix[i][j] < target) {
                j++;
            } else {
                return true;
            }
        }

        return false;
    }
};
