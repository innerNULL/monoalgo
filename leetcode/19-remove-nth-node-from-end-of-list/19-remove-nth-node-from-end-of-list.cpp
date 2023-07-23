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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) { return head; }

        ListNode* right_ptr = head;
        ListNode* left_ptr = head;      

        int32_t forward_steps = n + 1;
        //printf("dbg: forward_steps=%i\n", forward_steps);  
        while (forward_steps > 0) {
            if (right_ptr == NULL) { break; }
            right_ptr = right_ptr->next;
            forward_steps--;
        } 
        //printf("dbg: forward_steps=%i\n", forward_steps);
        if (forward_steps >= 1) { return head->next; }

        while (right_ptr != NULL) {
            right_ptr = right_ptr->next;
            left_ptr = left_ptr->next;
        }
        if (left_ptr->next->next == NULL) {
            left_ptr->next = NULL;
        } else {
            left_ptr->next = left_ptr->next->next; 
        }
        return head;
    }
};