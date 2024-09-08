/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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


#include <vector>


inline constexpr void tree_find_node(
    std::vector<TreeNode*>& dest, 
    TreeNode* root, 
    const int32_t val
) {
    if (root == nullptr) { return; }
    if (root->val == val) { dest.emplace_back(root); }
    tree_find_node(dest, root->left, val);
    tree_find_node(dest, root->right, val);
}


inline constexpr bool tree_contains_list(
    const TreeNode* root, 
    const ListNode* head
) {
    if (root == nullptr && head != nullptr) {
        return false; 
    }
    if (head == nullptr) { return true; }
    if (root->val != head->val) { return false; }
    return (
        tree_contains_list(root->right, head->next)
        || tree_contains_list(root->left, head->next)
    );
}


class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        TreeNode* tree_reader = root;
        ListNode* list_reader = head;
        std::vector<TreeNode*> cands = {};
        tree_find_node(cands, root, head->val);
        for (const TreeNode* cand : cands) {
            if (tree_contains_list(cand, head)) { return true; }
        }
        return false; 
    }
};
