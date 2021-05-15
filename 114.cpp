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
    void flatten(TreeNode* root) {
        stack<TreeNode*> stk;

        TreeNode *cur = root;
        while (cur) {
            if (cur->right) {
                stk.push(cur->right);
            }

            if (cur->left) {
                cur->right = cur->left;
                cur->left = nullptr;
            } else if (!stk.empty()) {
                cur->right = stk.top();
                stk.pop();
            }
            cur = cur->right;
        }
    }
};
