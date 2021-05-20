#include <vector>
#include <queue>
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
public:
    vector< vector<int> > levelOrder(TreeNode* root) {
        vector< vector<int> > res;
        queue<TreeNode*> q;

        if (!root) return res;
        q.push(root);

        while (!q.empty()) {
            vector<int> rl;
            size_t sz = q.size();
            for (size_t i = 0; i < sz; i++) {
                TreeNode *node = q.front();
                rl.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                q.pop();
            }
            res.push_back(rl);
        }

        return res;
    }
};

