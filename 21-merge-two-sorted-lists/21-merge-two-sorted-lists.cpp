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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy_head = new ListNode();
        ListNode* dummy_tail = dummy_head;
        
        ListNode* ptr_1 = list1;
        ListNode* ptr_2 = list2;
        
        while (ptr_1 && ptr_2) {
            if (ptr_1->val > ptr_2->val) {
                dummy_tail->next = ptr_2;
                ptr_2 = ptr_2->next;
            } else {
                dummy_tail->next = ptr_1;
                ptr_1 = ptr_1->next;
            }
            dummy_tail = dummy_tail->next;
        }
        while (ptr_1) {
            dummy_tail->next = ptr_1;
            ptr_1 = ptr_1->next;
            dummy_tail = dummy_tail->next;
        }
        while (ptr_2) {
            dummy_tail->next = ptr_2;
            ptr_2 = ptr_2->next;
            dummy_tail = dummy_tail->next;
        }
        return dummy_head->next;
    }
};