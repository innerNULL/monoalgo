/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")


inline constexpr int32_t
linkedlist_len(const ListNode* root) {
    int32_t out = 0;
    const ListNode* reader = root;
    while (reader != nullptr) {
        reader = reader->next;
        out += 1;
    }
    return out;
}


class Solution {
public:
    inline constexpr ListNode*
    getIntersectionNode(
        ListNode* headA, 
        ListNode* headB
    ) {
        ListNode* out = nullptr;
        const ListNode* reader_long;
        const ListNode* reader_short;
        const int32_t len_a = linkedlist_len(headA);
        const int32_t len_b = linkedlist_len(headB);
        if (len_a > len_b) {
            reader_long = headA;
            reader_short = headB;
        } else {
            reader_long = headB;
            reader_short = headA;
        }
        for (int32_t i = 0; i < std::abs(len_a - len_b); ++i) {
            reader_long = reader_long->next;
        }
        while (reader_long != nullptr && reader_short != nullptr) {
            if (reader_long == reader_short) {
                out = const_cast<ListNode*>(reader_long);
                break;
            }
            reader_long = reader_long->next;
            reader_short = reader_short->next;
        }
        return out;    
    }
};
