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


void tree2buffer(
    std::vector<TreeNode*>& dest, TreeNode* node
) {
    if (node) {
        dest.emplace_back(node);
        tree2buffer(dest, node->left);
        tree2buffer(dest, node->right);
    }
    return;
}


void buffer_print(
    const std::vector<TreeNode*>& buffer
) {
    for (const TreeNode* x : buffer) {
        printf("%i ", x->val);
    }
    printf("\n");
}


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::vector<TreeNode*> buffer = {};
        tree2buffer(buffer, root);
        std::sort(
            buffer.begin(),
            buffer.end(),
            [](TreeNode* a, TreeNode* b) {
                return a->val < b->val;
            }
        );
        //buffer_print(buffer);
        k = std::min(k, static_cast<int32_t>(buffer.size()));
        return buffer[k - 1]->val;
    }
};
