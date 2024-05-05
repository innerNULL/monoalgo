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


void traversal(std::vector<TreeNode*>& dest, TreeNode* node) {
    if (node != nullptr) {
        dest.emplace_back(node);
        traversal(dest, node->left);
        traversal(dest, node->right);
    }
    return;
}


class Solution {
public:
    void flatten(TreeNode* root) {
        std::vector<TreeNode*> nodes = {};
        traversal(nodes, root);
        for (size_t i = 0; i < nodes.size(); ++i) {
            nodes[i]->left = nullptr;
            if (i == nodes.size() - 1) {
                nodes[i]->right = nullptr;
            } else {
                nodes[i]->right = nodes[i + 1];
            }
        }
    }
};
