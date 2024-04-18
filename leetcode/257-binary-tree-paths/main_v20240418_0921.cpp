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


inline void 
iterate(
    std::set<std::string>& dest, 
    std::string curr_result, 
    const TreeNode* curr_node
) {
    curr_result = curr_result.size() == 0 ? curr_result : curr_result + "->";
    curr_result += std::to_string(curr_node->val);
    if (!curr_node->left && !curr_node->right) {
        dest.insert(curr_result); 
    } 
    if (curr_node->left) {
        iterate(dest, curr_result, curr_node->left);
    } 
    if (curr_node->right) {
        iterate(dest, curr_result, curr_node->right);
    }
    return;
}


class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        std::set<std::string> out = {};
        std::string tmp_result = "";
        iterate(out, tmp_result, root);
        return std::vector<std::string>(out.begin(), out.end());
    }
};
