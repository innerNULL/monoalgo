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


inline constexpr int32_t 
list_get_len(const ListNode* head) {
    int32_t len = 0;
    const ListNode* reader = head;
    while (reader != nullptr) {
        len += 1;
        reader = reader->next;
    }
    return len;
}


class Solution {
public:
    inline constexpr std::vector<ListNode*> 
    splitListToParts(ListNode* head, const int32_t k) {
        std::vector<ListNode*> parts = {};
        const int32_t list_len = list_get_len(head);
        int32_t remainder = -1;
        ListNode* reader = head;
        if (list_len < k) {
            remainder = k - list_len;
            while (reader != nullptr) {
                ListNode* next = reader->next;
                reader->next = nullptr;
                parts.emplace_back(reader);
                reader = next;
            }
            for (size_t i = 0; i < remainder; ++i) {
                parts.emplace_back(nullptr);
            }
        } else {
            remainder = list_len % k;
            while (reader != nullptr) {
                size_t part_size = (list_len -  remainder) / k;
                if (remainder > 0) {
                    remainder -= 1;
                    part_size += 1;
                }
                parts.emplace_back(reader);
                for (size_t i = 0; i < part_size - 1; ++i) {
                    reader = reader->next;
                }
                ListNode* next = reader->next;
                reader->next = nullptr;
                reader = next;
            }
        }
        return parts;
    }
};
