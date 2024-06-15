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


constexpr size_t
linkedlist_len(const ListNode* head) {
    size_t len = 0;
    const ListNode* reader = head;
    while (reader != nullptr) {
        len += 1;
        reader = reader->next;
    }
    return len;
}


constexpr ListNode* 
linkedlist_nth(ListNode* head, size_t n) {
    ListNode* reader = head;
    for (size_t i = 0; i < n; ++i) {
        if (reader == nullptr) {
            return nullptr;
        }
        reader = reader->next;
    }
    return reader;
}


class Solution {
public:
    inline ListNode* 
    swapNodes(ListNode* head, int k) {
        const size_t len = linkedlist_len(head);
        ListNode* left = linkedlist_nth(
            head, static_cast<size_t>(k - 1)
        );
        ListNode* right = linkedlist_nth(
            head, len - 1 - static_cast<size_t>(k - 1)
        );
        int32_t tmp = left->val;
        left->val = right->val;
        right->val = tmp;
        return head;
    }
};
