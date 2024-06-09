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


#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")


inline void
level_traversal(
    std::vector<std::vector<int32_t>>& dest, 
    TreeNode* node, 
    int32_t level
) {
    if (node == nullptr) {
        return;
    }
    while (static_cast<size_t>(level) > dest.size()) {
        dest.emplace_back(std::vector<int32_t>());
    }
    dest[level - 1].emplace_back(node->val);
    level_traversal(dest, node->left, level + 1);
    level_traversal(dest, node->right, level + 1);
    return;
}


class Solution {
public:
    inline std::vector<std::vector<int32_t>> 
    levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int32_t>> out;
        level_traversal(out, root, 1);
        std::reverse(out.begin(), out.end());
        return out;
    }
};
