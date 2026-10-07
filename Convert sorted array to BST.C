/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}


struct TreeNode* buildBST(int* nums, int start, int end) {
    
    if (start > end) {
        return NULL;
    }

    
    int mid = start + (end - start) / 2;
    
    
    struct TreeNode* root = newNode(nums[mid]);

    
    root->left = buildBST(nums, start, mid - 1);

    
    root->right = buildBST(nums, mid + 1, end);

    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return buildBST(nums, 0, numsSize - 1);
    
}
