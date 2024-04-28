/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* 
rotateRight(struct ListNode* head, int k) {
    struct ListNode* tail = head;
    int length = 0;
    while (true) {
        if (!tail) { break; }
        length += 1;
        if (!tail->next) {
            break;
        } else {
            tail = tail->next;
        }
    }
    //printf("dbg: length=%i\n", length);
    if (length == 0) { return head; }
    k = k % length;
    //printf("dbg: k=%i\n", k);
    if (k == 0) { return head; }
    struct ListNode* new_head = head;
    struct ListNode* new_tail = head;
    for (int i = 0; i < length - k; ++i) {
        if (i < length - k - 1) { 
            new_tail = new_tail->next; 
        }
        new_head = new_head->next;
    }
    tail->next = head;
    new_tail->next = NULL;
    return new_head;
}
