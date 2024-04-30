/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool 
contains(
    struct TreeNode* root, 
    struct TreeNode* node
) {
    if (node == NULL) {
        return true;
    } else if (root == NULL) {
        return false;
    } else if (root == node) {
        return true;
    } else {
        return contains(root->left, node) 
            || contains(root->right, node);
    }
    return false;
}


struct TreeNode* 
lowestCommonAncestor(
    struct TreeNode* root, 
    struct TreeNode* p, 
    struct TreeNode* q
) {
    if (!p || !q) {
        return root;
    } else if (root == NULL) {
        return NULL;
    } else if (root == q || root == q) {
        return root;
    } else {
        bool left_contains_p = contains(root->left, p);
        bool left_contains_q = contains(root->left, q);
        bool right_contains_p = contains(root->right, p);
        bool right_contains_q = contains(root->right, q);
        if (left_contains_p && left_contains_q) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (right_contains_p && right_contains_q) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
}
