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


void run_level_order_traversal(
        std::vector<std::vector<int> >& dest, 
        TreeNode* node, int32_t level) {
    if (node == NULL) { return; }
    if (dest.size() < level) { dest.resize(level); }

    int32_t level_idx = level - 1;
    std::vector<int>& curr_level_nodes = dest[level_idx];
    curr_level_nodes.emplace_back(node->val);
    run_level_order_traversal(dest, node->left, level + 1);
    run_level_order_traversal(dest, node->right, level + 1);
}


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int> > out;
        run_level_order_traversal(out, root, 1);
        return out;
    }
};