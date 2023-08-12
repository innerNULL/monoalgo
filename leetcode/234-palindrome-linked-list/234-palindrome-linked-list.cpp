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


int32_t ListNode_len(ListNode* head) {
    int32_t len = 0;
    while (head) {
        head = head->next;
        len++;
    }
    return len;
}


ListNode* ListNode_reverse(ListNode* head) {
    if (head == NULL) { return head; }
    ListNode* dummy_head = new ListNode();
    ListNode* dummy_second = NULL;
    ListNode* reader = head;
    while (reader) {
        ListNode* reader_next = reader->next;
        dummy_second = dummy_head->next;
        dummy_head->next = reader;
        dummy_head->next->next = dummy_second;
        reader = reader_next;
    }
    return dummy_head->next;
}


ListNode* ListNode_indexer(ListNode* head, const int32_t idx) {
    int32_t curr_idx = 0;
    ListNode* reader = head;
    while (head) {
        if (curr_idx == idx) { return reader; }
        reader = reader->next;
        curr_idx++;
    }
    return NULL;
}



class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL or head->next == NULL) { return true; }
        int32_t len = ListNode_len(head);
        ListNode* first_half = head;
        int32_t second_half_head_idx = len % 2 == 0 ? len / 2 : len / 2 + 1;
        ListNode* second_half = ListNode_indexer(head, second_half_head_idx);
        ListNode* reversed_2nd_half = ListNode_reverse(second_half);
        ListNode* dbg = reversed_2nd_half;
        while (reversed_2nd_half && first_half) {
            if (first_half->val != reversed_2nd_half->val) { return false; }
            first_half = first_half->next;
            reversed_2nd_half = reversed_2nd_half->next;
        }
        return true;
    }
};
