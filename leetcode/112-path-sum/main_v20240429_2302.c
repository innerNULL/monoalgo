/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return false;
    } else if (root->left == NULL && root->right == NULL) {
        return root->val == targetSum;
    } else {
        const int next_target = targetSum - root->val;
        return hasPathSum(root->left, next_target) 
            || hasPathSum(root->right, next_target);
    }
}
