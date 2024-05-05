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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy_head = new ListNode(-1);
        ListNode* dummy_tail = dummy_head;
        ListNode* reader = head;
        int32_t dup_val = -10000; // magic number
        while (reader != nullptr) {
            while (
                reader->next != nullptr 
                && reader->val == reader->next->val
            ) {
                dup_val = reader->val;
                reader = reader->next;
            }
            if (dup_val != reader->val) {
                //printf("dbg: insert_val=%i\n", reader->val);
                dummy_tail->next = reader;
                dummy_tail = dummy_tail->next;
            }
            reader = reader->next;
        }
        dummy_tail->next = nullptr;
        return dummy_head->next;
    }
};
