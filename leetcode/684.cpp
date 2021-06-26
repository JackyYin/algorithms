class DSU {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int size);
    int find(int idx);
    bool join(int a, int b);
};

DSU::DSU(int size)
{
    parent = vector<int> (size, 0);
    rank = vector<int> (size, 0);

    for (int i = 0; i < size; i++) {
        parent[i] = i;
    }
}

int DSU::find(int idx)
{
    if (parent[idx] != idx) {
        parent[idx] = find(parent[idx]);
    }
    return parent[idx];
}

bool DSU::join(int a, int b)
{
    int pa = find(a);
    int pb = find(b);
    cout << pa << " " << pb << endl;
    if (pa == pb) return false;

    if (rank[pa] > rank[pb]) {
        parent[pb] = pa;
    } else if (rank[pb] > rank[pa]) {
        parent[pa] = pb;
    } else {
        parent[pb] = pa;
        rank[pa]++;
    }
    return true;
}


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU *dsu = new DSU(edges.size() + 1);
        vector<int> res;
        for (auto &edge : edges) {
            if (!dsu->join(edge[0], edge[1])) {
                res = edge;
            }
        }
        
        delete dsu;
        return res;
    }
};
