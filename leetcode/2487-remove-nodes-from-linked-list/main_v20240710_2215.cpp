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
    inline ListNode* 
    removeNodes(ListNode* head) {
        std::vector<ListNode*> nodes;
        ListNode* reader = head;
        while (reader != nullptr) {
            ListNode* next = reader->next;
            reader->next = nullptr;
            nodes.emplace_back(reader);
            reader = next;
        }
        std::vector<int32_t> cand_idxs;
        int32_t right_max = 0;
        for (int32_t i = nodes.size() - 1; i >= 0; --i) {
            if (i == static_cast<int32_t>(nodes.size() - 1)) {
                cand_idxs.emplace_back(i);
                right_max = nodes[i]->val; 
            } else {
                if (nodes[i]->val >= right_max) {
                    cand_idxs.emplace_back(i);
                    right_max = nodes[i]->val; 
                }
            }
        }
        ListNode* new_head = nullptr;
        ListNode* new_tail = nullptr;
        for (int32_t i = cand_idxs.size() - 1; i >= 0; --i) {
            size_t idx = static_cast<size_t>(cand_idxs[i]);
            if (new_head == nullptr) {
                new_head = nodes[idx];
                new_tail = new_head; 
            } else {
                new_tail->next = nodes[idx];
                new_tail = new_tail->next;
            }
        }
        new_tail->next = nullptr;
        return new_head;
    }
};
