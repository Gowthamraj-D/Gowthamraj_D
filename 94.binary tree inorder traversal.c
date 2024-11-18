/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    // Helper function to perform inorder traversal
    void inorderTraversalHelper(struct TreeNode* root, int* result, int* returnSize) {
        if (root == NULL) return;
        inorderTraversalHelper(root->left, result, returnSize);
        result[(*returnSize)++] = root->val;
        inorderTraversalHelper(root->right, result, returnSize);
    }

    *returnSize = 0;
    int* result = (int*)malloc(100 * sizeof(int)); // Allocate memory for the result array
    inorderTraversalHelper(root, result, returnSize);
    return result;
}
