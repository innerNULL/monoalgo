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


#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd_head = new ListNode {0, nullptr};
        ListNode* even_head = new ListNode {0,  nullptr};
        ListNode* odd_tail = odd_head;
        ListNode* even_tail = even_head;
        ListNode* reader = head;
        size_t id = 1;
        while (reader != nullptr) {
            if (id % 2 == 0) {
                even_tail->next = reader;
                even_tail = even_tail->next;
            } else {
                odd_tail->next = reader;
                odd_tail = odd_tail->next;
            }
            reader = reader->next;
            id += 1;
        }
        ListNode* dummy_head = new ListNode {0, nullptr};
        ListNode* dummy_tail = dummy_head;
        if (odd_head != odd_tail) {
            dummy_tail->next = odd_head->next;
            dummy_tail = odd_tail;
        }
        if (even_head != even_tail) {
            dummy_tail->next = even_head->next;
            dummy_tail = even_tail;
        }
        dummy_tail->next = nullptr;
        return dummy_head->next;
    }
};
