#include <vector>
using namespace std;

class Solution {
public:
    void discover(vector< vector<int> >& grid, int row, int col, int& sum) {
        sum++;
        grid[row][col] = 2;

        if (row > 0 && grid[row - 1][col] == 1) {
            discover(grid, row - 1, col, sum);
        }
        
        if (row < grid.size() - 1 && grid[row + 1][col] == 1) {
            discover(grid, row + 1, col, sum);
        }
        
        if (col > 0 && grid[row][col - 1] == 1) {
            discover(grid, row, col - 1, sum);
        }
        
        if (col < grid[row].size() - 1 && grid[row][col + 1] == 1) {
            discover(grid, row, col + 1, sum);
        }
    }

    int maxAreaOfIsland(vector< vector<int> >& grid) {
        int Max = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    int s = 0;
                    discover(grid, i, j, s);
                    Max = max(Max, s);
                }
            }
        }
        return Max;
    }
};
