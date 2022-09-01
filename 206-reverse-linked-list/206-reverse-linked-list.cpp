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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) { return head; }
        if (head->next == NULL) { return head; }
        
        ListNode* dummy_head = new ListNode();
        ListNode* ptr = head;
        
        while (ptr) {
            //printf("%i\n", ptr->val);
            ListNode* curr_node = ptr;
            ListNode* next_node = ptr->next;
            ListNode* dummy_next = dummy_head->next;
            dummy_head->next = curr_node;
            dummy_head->next->next = dummy_next;
            ptr = next_node;
        }
        return dummy_head->next;
    }
};