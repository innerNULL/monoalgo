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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) { return NULL; }
        
        ListNode* dummy_head = new ListNode();
        ListNode* dummy_tail = dummy_head;
        ListNode* iter = head;
        while (iter != NULL) {
            ListNode* first = NULL;
            ListNode* second = NULL;
            first = iter;
            if (first->next != NULL) { 
                iter = iter->next->next;
                second = first->next; 
            } else {
                iter = iter->next;
            }

            first->next = NULL;
            if (second != NULL) {
                dummy_tail->next = second;
                dummy_tail->next->next = first;
                dummy_tail = dummy_tail->next->next; 
            } else {
                dummy_tail->next = first;
                dummy_tail = dummy_tail->next;
            }
        }
        return dummy_head->next;
    }
};