/* From each node, compute the height of its right and left subtrees. The
 * node with the highest sum of L/R heights represents the diameter */
int get_diameter(struct TreeNode* root, int *diameter){

    /* Base case: if a child node is NULL, return 0 */
    if (!root) return 0;
    else
    {
        int left_height   = get_diameter(root->left,  diameter);
        int right_height  = get_diameter(root->right, diameter);
        int node_diameter = left_height + right_height;

        /* Record the max node diameter found across the entire tree; At the
         * end of the function this should contain the max diameter of the entire
         * tree */
        *diameter = (node_diameter > *diameter) ? node_diameter : *diameter;

        /* Now, compute the max side height and return that + 1 */
        return ((left_height > right_height) ? left_height : right_height) + 1;
    }
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int diameterOfBinaryTree(struct TreeNode* root){

    int diameter = 0;
    get_diameter(root, &diameter);

    return diameter;
}
