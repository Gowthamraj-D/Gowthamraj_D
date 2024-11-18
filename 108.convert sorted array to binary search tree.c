struct TreeNode* sortedArrayToBSTHelper(int* nums, int left, int right) {
    if (left > right) return NULL;

    int mid = left + (right - left) / 2;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = nums[mid];
    node->left = sortedArrayToBSTHelper(nums, left, mid - 1);
    node->right = sortedArrayToBSTHelper(nums, mid + 1, right);

    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return sortedArrayToBSTHelper(nums, 0, numsSize - 1);
}
