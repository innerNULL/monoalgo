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


void count(int32_t* cnt, TreeNode* node) {
    if (node != nullptr) {
        *cnt += 1;
        count(cnt, node->left);
        count(cnt, node->right);
    }
    return;
}


class Solution {
public:
    int countNodes(TreeNode* root) {
        int32_t cnt = 0;
        count(&cnt, root);
        return cnt;
    }
};
