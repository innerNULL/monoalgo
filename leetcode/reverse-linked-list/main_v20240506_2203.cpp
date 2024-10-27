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


#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")


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
