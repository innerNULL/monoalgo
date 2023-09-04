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
        ListNode* dummy_head = new ListNode();
        ListNode* dummy_tail = dummy_head;
        ListNode* reader = head;
        while (reader) {
            ListNode* next = reader->next;
            if (dummy_head == dummy_tail) {
                dummy_head->next = reader;
                dummy_tail = dummy_tail->next;
            } else {
                if (reader->val != dummy_tail->val) {
                    dummy_tail->next = reader;
                    dummy_tail = dummy_tail->next;
                }
            }
            dummy_tail->next = NULL;
            reader = next;
        }
        return dummy_head->next; 
    }
};
