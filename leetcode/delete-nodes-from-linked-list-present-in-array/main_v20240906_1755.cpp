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


#include <set>


class Solution {
public:
    inline ListNode* modifiedList(
        const std::vector<int32_t>& nums, 
        ListNode* head
    ) {
        const std::set<int32_t> num_set(nums.begin(), nums.end());
        ListNode* new_head = nullptr;
        ListNode* new_tail = nullptr;
        ListNode* reader = head;
        while (reader != nullptr) {
            int32_t val = reader->val;
            if (num_set.find(val) != num_set.end()) {
                reader = reader->next;
                continue;
            }
            ListNode* next = reader->next;
            if (new_head == nullptr) {
                new_head = reader;
                new_tail = new_head;
            } else {
                new_tail->next = reader;
                new_tail = new_tail->next;
            }
            reader->next = nullptr;
            reader = next;
        }
        return new_head; 
    }
};
