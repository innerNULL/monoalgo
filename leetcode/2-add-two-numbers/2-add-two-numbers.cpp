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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy_head = new ListNode(0);
        ListNode* writer = dummy_head;
        
        ListNode* l1_ptr = l1;
        ListNode* l2_ptr = l2;
        int32_t carry = 0;
        while (l1_ptr != NULL || l2_ptr != NULL) {
            int32_t l1_val = 0;
            int32_t l2_val = 0;
            int32_t curr_sum = 0;
            if (l1_ptr != NULL) { l1_val = l1_ptr->val; }
            if (l2_ptr != NULL) { l2_val = l2_ptr->val; }
            
            //printf("%i, %i, %i\n", l1_val, l2_val, carry);
            curr_sum = l1_val + l2_val + carry;
            carry = 0;
            if (curr_sum > 9) {
                carry = 1;
                curr_sum -= 10;
            }
            
            writer->next = new ListNode(curr_sum);
            if (l1_ptr != NULL) { l1_ptr = l1_ptr->next; }
            if (l2_ptr != NULL) { l2_ptr = l2_ptr->next; }
            writer = writer->next;
        }
        if (carry == 1) { writer->next = new ListNode(1); }
        return dummy_head->next;
    }
};