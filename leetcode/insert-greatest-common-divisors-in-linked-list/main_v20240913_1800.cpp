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


#include <numeric>


class Solution {
public:
    inline constexpr ListNode* 
    insertGreatestCommonDivisors(ListNode* head) {
        ListNode* left = head;
        ListNode* right = head ? head->next : nullptr;
        while (left != nullptr && right != nullptr) { 
            const int32_t left_val = left->val;
            const int32_t right_val = right->val;
            ListNode* insert = new ListNode(std::gcd(left_val, right_val));
            left->next = insert;
            insert->next = right;
            left = right;
            right = left ? left->next : nullptr;
        }
        return head;     
    }
};
