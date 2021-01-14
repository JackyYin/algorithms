#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};


void inorder(struct TreeNode *node, int *arr, int *len, int *stack, int *stackLen) {
    if (!node) return;

    stack[(*stackLen)++] = node->val;
    inorder(node->left, arr, len, stack, stackLen);
    arr[(*len)++] = stack[--(*stackLen)];
    inorder(node->right, arr, len, stack, stackLen);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *arr = malloc(sizeof(int) * 100);
    *returnSize = 0;
    int stack[100];
    int stackSize = 0;
    inorder(root, arr, returnSize, stack, &stackSize);
    return arr;
}
