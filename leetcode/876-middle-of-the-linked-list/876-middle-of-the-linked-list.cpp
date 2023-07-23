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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* faster_ptr = head;
        ListNode* slower_ptr = head;
        while (faster_ptr) {
            faster_ptr = faster_ptr->next;
            if (faster_ptr == NULL) { break; }
            faster_ptr = faster_ptr->next;
            slower_ptr = slower_ptr->next;
        }
        return slower_ptr;
    }
};