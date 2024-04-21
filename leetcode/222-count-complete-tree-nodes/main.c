/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int cnt(struct TreeNode* node) {
    if (node) {
        return 1 + cnt(node->left) + cnt(node->right);
    } else {
        return 0;
    }
}


int countNodes(struct TreeNode* root) {
    return cnt(root);
}
