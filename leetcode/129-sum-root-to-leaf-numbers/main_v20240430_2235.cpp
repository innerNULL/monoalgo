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


void run(
    std::vector<int32_t>& recorder, 
    std::string curr_result, 
    TreeNode* node
) {
    if (!node) {
        return;
    } else if (!node->left && !node->right) {
        if (curr_result.size() != 0) {
            recorder.emplace_back(
                std::stoi(curr_result+ std::to_string(node->val))
            );
        }
    } else {
        curr_result += std::to_string(node->val);
        if (node->left) {
            run(recorder, curr_result, node->left);
        }
        if (node->right) {
            run(recorder, curr_result, node->right);
        }
    }
}


class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) { return 0; }
        if (!root->left && !root->right) { return root->val; }
        std::vector<int32_t> recorder = {};
        std::string result = ""; 
        run(recorder, result, root);
        int32_t out = 0;
        for (auto x : recorder) {
            //printf("dbg: x=%i\n", x);
            out += x;
        }
        return out;
    }
};
