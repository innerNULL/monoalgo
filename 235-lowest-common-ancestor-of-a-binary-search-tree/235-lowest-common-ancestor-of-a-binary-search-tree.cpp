/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


bool contains_node(TreeNode* node, TreeNode* target) {
    if (node == NULL) { return false; }
    if (node == target) { return true; }
    return contains_node(node->left, target) 
        || contains_node(node->right, target);
}


void get_lowest_common_ancestor(
        TreeNode** dest, TreeNode* node, TreeNode* p, TreeNode* q) {
    if (node == NULL) { return; }

    bool p_at_left = contains_node(node->left, p);
    bool p_at_right = contains_node(node->right, p);
    bool q_at_left = contains_node(node->left, q);
    bool q_at_right = contains_node(node->right, q);
    //printf("dbg: p_at_left=%d, p_at_right=%d\n", p_at_left, p_at_right);
    //printf("dbg: q_at_left=%d, q_at_right=%d\n", q_at_left, q_at_right);
    
    if ( !(p_at_left || p_at_right) || !(q_at_left || q_at_right) ) {
        //printf("dbg: condition 1\n");
        return;
    }
    
    if (p_at_left & q_at_left) {
        //printf("dbg: condition 2\n");
        *dest = node->left;
        get_lowest_common_ancestor(dest, node->left, p, q);
    } else if (p_at_right && q_at_right) {
        //printf("dbg: condition 3\n");
        get_lowest_common_ancestor(dest, node->right, p, q);
    } else if ( (p_at_left && q_at_right) || (p_at_right && q_at_left) ) {
        //printf("dbg: condition 4\n");
        *dest = node;
        return;
    }
}


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p && contains_node(root, q)) { return root; }
        if (root == q && contains_node(root, p)) { return root; }
        
        TreeNode* result = NULL;
        get_lowest_common_ancestor(&result, root, p, q);
        return result;
    }
};