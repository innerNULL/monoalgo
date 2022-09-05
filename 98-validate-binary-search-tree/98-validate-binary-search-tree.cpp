/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


bool is_bst(
        TreeNode* node, 
        TreeNode* upper_bound=NULL, TreeNode* lower_bound=NULL) {
    //printf("dbg: upper_bound=%i, lower_bound=%i\n", upper_bound, lower_bound);
    if (node == NULL) { return true; }
    if (upper_bound != NULL && node->val >= upper_bound->val) { return false; }
    if (lower_bound != NULL && node->val <= lower_bound->val) { return false; }
    return is_bst(node->left, node, lower_bound) 
        && is_bst(node->right, upper_bound, node);
}


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) { return true; }
        if (root->left == NULL && root->right == NULL) { return true; }
        return is_bst(root, NULL, NULL);
    }
};