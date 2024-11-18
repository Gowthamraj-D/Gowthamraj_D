bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // If both nodes are NULL, they are the same
    if (p == NULL && q == NULL) return true;
    // If one of the nodes is NULL, they are not the same
    if (p == NULL || q == NULL) return false;
    // If the values of the nodes are different, they are not the same
    if (p->val != q->val) return false;
    // Recursively check the left and right subtrees
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
