class Solution {
public:
    void bfs(vector<set<int>> &connected, vector<bool> &visited, int idx) {
        visited[idx] = true;

        queue<int> tmpq;
        for (auto it = connected[idx].begin(); it != connected[idx].end(); it++) {
            tmpq.push(*it);
        }

        int levelSz = tmpq.size();
        while (!tmpq.empty()) {
            for (int i = 0; i < tmpq.size(); i++) {
                int cur = tmpq.front();
                if (!visited[cur]) {
                    visited[cur] = true;
                    for (auto it = connected[cur].begin(); it != connected[cur].end(); it++) {
                        tmpq.push(*it);
                    }
                }
                tmpq.pop();
            }
        }
    }

    void dfs(vector<set<int>> &connected, vector<bool> &visited, int idx) {
        visited[idx] = true;

        for (auto it = connected[idx].begin(); it != connected[idx].end(); it++) {
            if (!visited[*it]) {
                dfs(connected, visited, *it);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;

        vector<set<int>> connected(n);
        for (int i = 0; i < connections.size(); i++) {
            connected[connections[i][0]].insert(connections[i][1]);
            connected[connections[i][1]].insert(connections[i][0]);
        }

        int res = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(connected, visited, i);
                res++;
            }
        }
        return res - 1;
    }
};
