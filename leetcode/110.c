#include <stdlib.h>
#include <stdbool.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfs (struct TreeNode* node) {
    if (!node) return 0;

    int left = dfs(node->left);
    int right = dfs(node->right);

    //printf("%d, %d, %d \n", node->val, left, right);
    if (left < 0 || right < 0) return -1;

    if (abs(left - right) > 1) return -1;

    return MAX(left, right) + 1;
}

bool isBalanced(struct TreeNode* root){
    return dfs(root) >= 0;
}
