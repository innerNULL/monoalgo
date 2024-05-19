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


constexpr void tree_get_leave_vals(
    std::vector<int32_t>& dest, TreeNode* node
) {
    if (node == nullptr) { return; }
    if (node->left == nullptr && node->right == nullptr) {
        dest.emplace_back(node->val);
        return;
    } else {
        tree_get_leave_vals(dest, node->left);
        tree_get_leave_vals(dest, node->right);
    }
    return;
}


class Solution {
public:
    inline bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int32_t> leave_vals1 = {};
        std::vector<int32_t> leave_vals2 = {};
        tree_get_leave_vals(leave_vals1, root1);
        tree_get_leave_vals(leave_vals2, root2);
        if (leave_vals1.size() != leave_vals2.size()) {
            return false;
        } 
        for (size_t i = 0; i < leave_vals1.size(); ++i) {
            if (leave_vals1[i] != leave_vals2[i]) { return false; }
        }
        return true;
    }
};
