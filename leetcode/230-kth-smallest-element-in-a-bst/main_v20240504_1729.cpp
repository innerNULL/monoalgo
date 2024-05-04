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


void tree2buffer_inorder_traversal(
    std::vector<int32_t>& dest, TreeNode* node
) {
    if (node != nullptr) {
        tree2buffer_inorder_traversal(dest, node->left);
        dest.emplace_back(node->val);
        tree2buffer_inorder_traversal(dest, node->right);
    }
    return;
}


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::vector<int32_t> buffer = {};
        tree2buffer_inorder_traversal(buffer, root);
        return buffer[k - 1];
    }
};
