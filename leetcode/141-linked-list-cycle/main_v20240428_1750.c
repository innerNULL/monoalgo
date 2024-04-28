/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (!head) { return false; }
    struct ListNode* slower = head;
    struct ListNode* faster = head;
    while (true) {
        slower = slower->next;
        faster = faster->next;
        if (!faster) { break; }
        faster = faster->next;
        if (!faster) { break; }
        if (slower == faster) { return true; }
    }
    return false;
}
