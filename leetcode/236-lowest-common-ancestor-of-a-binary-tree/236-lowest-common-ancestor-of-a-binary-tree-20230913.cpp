/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


bool containes_node(TreeNode* root, TreeNode* target) {
    if (target == NULL) { 
        return true; 
    } else if (root == NULL) {
        return false;
    } else {
        return (root->val == target->val) 
            || containes_node(root->left, target) 
            || containes_node(root->right, target);
    }
}


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val == p->val || root->val == q->val) { return root; } 
        bool p_in_left = containes_node(root->left, p);
        bool q_in_left = containes_node(root->left, q);
        bool p_in_right = p_in_left ? false : true;
        bool q_in_right = q_in_left ? false : true;
        if (p_in_left && q_in_left) {
            return this->lowestCommonAncestor(root->left, p, q);
        } else if (p_in_right && q_in_right) {
            return this->lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
};
