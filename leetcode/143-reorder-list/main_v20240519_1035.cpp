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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) { return; }
        std::vector<ListNode*> nodes = {};
        ListNode* reader = head;
        while (reader != nullptr) {
            nodes.emplace_back(reader);
            reader = reader->next;
        }
        ListNode* dummy_head = new ListNode;
        ListNode* dummy_tail = dummy_head;
        size_t left_idx = 0;
        size_t right_idx = nodes.size() - 1;
        while (left_idx <= right_idx) {
            ListNode* left = nodes[left_idx];
            ListNode* right = nodes[right_idx];
            left->next = nullptr;
            right->next = nullptr;
            if (left_idx != right_idx) {
                //printf("(dbg) left is null: %i\n", left == nullptr);
                //printf("(dbg) right is null: %i\n", right == nullptr);
                dummy_tail->next = left;
                dummy_tail->next->next = right;
                dummy_tail = dummy_tail->next->next;
            } else {
                dummy_tail->next = left;
            }
            left_idx += 1;
            right_idx -= 1;
        }
        head = dummy_head->next;
        return;
    }
};
