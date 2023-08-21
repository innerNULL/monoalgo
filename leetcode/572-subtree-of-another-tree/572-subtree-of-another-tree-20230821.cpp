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


bool tree_equal(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    } else if (root1 != NULL and root2 != NULL) {
        return root1->val == root2->val 
            && tree_equal(root1->left, root2->left) 
            && tree_equal(root1->right, root2->right);
    } else {
        return false;
    }
}


class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) { return false; }
        if (subRoot == NULL) { return true; }
        return tree_equal(root, subRoot) 
            || isSubtree(root->left, subRoot) 
            || isSubtree(root->right, subRoot);
    }
};
