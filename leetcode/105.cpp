#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    unordered_map<int, int> inMap;

    TreeNode* dfs(int& preIdx, int ilb, int irb, vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = new TreeNode(preorder[preIdx]);

        int midIdx = inMap[preorder[preIdx]];

        // construct left tree
        if (midIdx - ilb > 0) {
            root->left = dfs(++preIdx, ilb, midIdx - 1, preorder, inorder);
        }

        // construct right tree
        if (irb - midIdx > 0) {
            root->right = dfs(++preIdx, midIdx + 1, irb, preorder, inorder);
        }

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        size_t n = preorder.size();

        // O(n)
        for (int i = 0; i < (int) n; i++) {
            inMap[inorder[i]] = i;
        }

        int idx = 0;
        // O(n)
        return dfs(idx, 0, n - 1, preorder, inorder);
    }
};
