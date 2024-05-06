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


inline void traversal(
    std::unordered_map<int32_t, std::vector<int32_t>>& dest, 
    TreeNode* node,
    int32_t level
) {
    if (node != nullptr) {
        if (dest.find(level) == dest.end()) {
            dest[level] = {};
        }
        dest[level].emplace_back(node->val);
        traversal(dest, node->left, level + 1);
        traversal(dest, node->right, level + 1);
    }
    return;
}


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int32_t>> out = {};
        std::unordered_map<int32_t, std::vector<int32_t>> 
        recorder = {};
        traversal(recorder, root, 0);
        for (size_t i = 0; i < recorder.size(); ++i) {
            out.emplace_back(std::move(recorder[i]));
        }
        return out;
    }
};
