/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(
    struct ListNode* list1, struct ListNode* list2
) {
    struct ListNode dummy_head = {.val = 0, .next = NULL};
    struct ListNode* writter = &dummy_head;
    struct ListNode* reader1 = list1;
    struct ListNode* reader2 = list2;
    while (reader1 && reader2) {
        if (reader1->val <= reader2->val) {
            struct ListNode* reader1_next = reader1->next;
            writter->next = reader1;
            reader1 = reader1_next;
        } else {
            struct ListNode* reader2_next = reader2->next;
            writter->next = reader2;
            reader2 = reader2_next;
        }
        writter = writter->next;
    }
    if (reader1) { writter->next = reader1; }
    if (reader2) { writter->next = reader2; }
    return dummy_head.next;
}
