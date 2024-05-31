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
    constexpr ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr) {
            return head;
        } else if (head->next == nullptr) {
            return nullptr;
        }
        const ListNode* faster = head;
        ListNode* slower = head;
        ListNode* last_slower = nullptr;
        while (true) {
            last_slower = slower;
            slower = slower->next;
            faster = faster->next; 
            if (faster->next == nullptr) { break; }
            faster = faster->next; 
            if (faster->next == nullptr) { break; }
        }
        last_slower->next = slower->next;
        return head;
    }
};
