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
    ListNode* middleNode(ListNode* head) {
        if (head == NULL || head->next == NULL) { return head; }
        ListNode* slower = head;
        ListNode* faster = head;
        int32_t len = 0; 
        while (true) {
            if (faster == NULL) { break; }
            faster = faster->next;
            if (faster == NULL) { break; }
            faster = faster->next;
            slower = slower->next;
        }
        return slower;
    }
};
