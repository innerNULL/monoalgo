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


void vec_print(const std::vector<TreeNode*>& vec) {
    for (auto x : vec) {
        printf("%i ", x->val);
    }
    printf("\n");
}


void tree_level_storage(
    std::unordered_map<int32_t, std::vector<TreeNode*>>& dest,
    int32_t level, 
    TreeNode* node
) {
    if (node == nullptr) { return; }
    if (dest.find(level) == dest.end()) { dest[level] = {}; }
    dest[level].emplace_back(node);
    tree_level_storage(dest, level + 1, node->left);
    tree_level_storage(dest, level + 1, node->right);
    return;
}


class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        std::unordered_map<int32_t, std::vector<TreeNode*>> levels = {};
        tree_level_storage(levels, 1, root);
        //printf("dbg: levels.size()=%i\n", levels.size());
        int32_t level = 1;
        while (levels.find(level) != levels.end()) {
            if (level % 2 == 0) {
                std::vector<TreeNode*> nodes = levels[level];
                //vec_print(nodes);
                size_t left = 0;
                size_t right = nodes.size() - 1;
                while (left < right) {
                    int32_t left_val = nodes[left]->val;
                    nodes[left]->val = nodes[right]->val;
                    nodes[right]->val = left_val;
                    left += 1;
                    right -= 1;
                }
            }
            level += 1;
        }
        return root;
    }
};
