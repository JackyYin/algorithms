#include <vector>
#include <stack>
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
    vector< vector<int> > zigzagLevelOrder(TreeNode* root) {
        if (!root) return vector< vector<int> >();

        vector< vector<int> > ans;
        stack<TreeNode*> stk;
        stk.push(root);

        bool direction = 1;
        while (!stk.empty()) {
            vector<int> row;

            stack<TreeNode*> tmp;
            while (!stk.empty() > 0) {
                TreeNode* node = stk.top();
                stk.pop();
                row.push_back(node->val);

                if (direction) {
                    if (node->left) tmp.push(node->left);
                    if (node->right) tmp.push(node->right);
                } else {
                    if (node->right) tmp.push(node->right);
                    if (node->left) tmp.push(node->left);
                }
            }

            ans.push_back(row);
            // change direction
            direction ^= 1;
            stk = tmp;
        }

        return ans;
    }
};
