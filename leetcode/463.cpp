class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int sum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    sum += 4;
                    if (i < m - 1 && grid[i + 1][j]) {
                        sum -= 2;
                    }
                    if (j < n - 1 && grid[i][j + 1]) {
                        sum -= 2;
                    }
                }
            }
        }
        return sum;
    }
};
