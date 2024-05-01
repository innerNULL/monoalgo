/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool
bst_verify(
    struct TreeNode* node, 
    struct TreeNode* lower_bound, 
    struct TreeNode* upper_bound
) {
    if (!node) {
        return true;
    } 
    if (upper_bound && node->val >= upper_bound->val) {
        return false;
    }
    if (lower_bound && node->val <= lower_bound->val) {
        return false;
    }
    return (
        bst_verify(node->left, lower_bound, node) 
        && bst_verify(node->right, node, upper_bound)
    );
}


bool isValidBST(struct TreeNode* root) {
    if (!root || !root->left && !root->right) {
        return true;
    }
    return bst_verify(root, NULL, NULL);
}
