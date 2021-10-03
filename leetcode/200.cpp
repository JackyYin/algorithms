class Solution {
public:
    int find(vector<int> &parents, int idx) {
        if (parents[idx] == idx) return idx;
        return find(parents, parents[idx]);
    }

    void join(vector<int> &parents, vector<int> &ranks, int x, int y) {
        int rootx = find(parents, x);
        int rooty = find(parents, y);

        if (ranks[rootx] > ranks[rooty]) {
            parents[rooty] = rootx;
        } else {
            parents[rootx] = rooty;
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<int> parents;
        vector<int> ranks;

        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                parents.push_back(i * n + j);
                ranks.push_back(0);
            }
        }

        int seaArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    if (i < m - 1 && grid[i + 1][j] == '1') {
                        join(parents, ranks, i * n + j, (i + 1) * n + j);
                    }
                    if (j < n - 1 && grid[i][j + 1] == '1') {
                        join(parents, ranks, i * n + j, i * n + j + 1);
                    }
                } else {
                    seaArea++;
                }
            }
        }

        set<int> myset;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                myset.insert(find(parents, i * n + j));
            }
        }
        return myset.size() - seaArea;
    }
};
