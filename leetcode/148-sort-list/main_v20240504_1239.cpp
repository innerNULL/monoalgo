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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        std::vector<ListNode*> cache = {};
        ListNode* reader = head;
        while (reader != nullptr) {
            cache.emplace_back(reader);
            reader = reader->next;
        } 
        std::sort(
            cache.begin(), 
            cache.end(),
            [](ListNode* a, ListNode* b) { return a->val < b->val; }
        );
        for (size_t i = 1; i < cache.size(); ++i) {
            cache[i - 1]->next = cache[i];
        }
        cache[cache.size() - 1]->next = NULL;
        return cache[0];
    }
};
