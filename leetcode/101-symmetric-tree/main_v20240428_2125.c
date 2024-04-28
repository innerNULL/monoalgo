/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool is_symmetric(struct TreeNode* a, struct TreeNode* b) {
    if (a && b) {
        return (a->val == b->val) 
            && is_symmetric(a->left, b->right) 
            && is_symmetric(a->right, b->left);
    } else if (!a && !b) {
        return true;
    } else {
        return false;
    }
}


bool isSymmetric(struct TreeNode* root) {
    if (!root) {
        return true;
    } else if (!root->left && !root->right) {
        return true;
    } else if (root->left && root->right) {
        return is_symmetric(root->left, root->right);
    } else {
        return false;
    }
}
