class Solution {
public:
    int find (vector<int> &parents, int idx) {
        if (parents[idx] == idx) return idx;
        return find(parents, parents[idx]);
    }

    void join (vector<int> &ranks, vector<int> &parents, int x, int y) {
        int rootx = find(parents, x);
        int rooty = find(parents, y);

        if (ranks[rootx] > ranks[rooty]) {
            parents[rooty] = rootx;
        } else {
            parents[rootx] = rooty;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;

        vector<int> parents(n);
        vector<int> ranks(n);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
            ranks[i] = 0;
        }

        for (int i = 0; i < connections.size(); i++) {
            join(ranks, parents, connections[i][0], connections[i][1]);
        }

        set<int> networks;
        for (int i = 0; i < n; i++) {
            networks.insert(find(parents, i));
        }
        return networks.size() - 1;
    }
};
