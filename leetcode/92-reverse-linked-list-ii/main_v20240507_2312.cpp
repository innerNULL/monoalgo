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


void listnodes_to_vec(
    std::vector<ListNode*>& dest, ListNode* head
) {
    ListNode* reader = head;
    while (reader != nullptr) {
        dest.emplace_back(reader);
        reader = reader->next;
    }
}

class Solution {
public:
    ListNode* reverseBetween(
        ListNode* head, int left, int right
    ) {
        std::vector<ListNode*> nodes = {};
        listnodes_to_vec(nodes, head);  
        //for (auto x: nodes) { printf("%i\n", x->val); } 
        if (left == right || nodes.size() == 1) {
            return head;
        } else if (nodes.size() == 2) {
            nodes[0]->next = nullptr;
            nodes[1]->next = nodes[0];
            return nodes[1];
        }
        left -= 1;
        right -= 1;
        while (left < right) {
            //printf("dbg: left=%i, right=%i\n", left, right);
            ListNode* tmp = nodes[left];
            nodes[left] = nodes[right];
            nodes[right] = tmp;
            left += 1;
            right -= 1;
        }
        ListNode* new_head = nullptr;
        ListNode* new_tail = nullptr;
        for (int32_t i = 0; i < nodes.size(); ++i) {
            ListNode* curr = new ListNode(nodes[i]->val);
            if (new_head == nullptr) {
                new_head = curr;
                new_tail = curr;
            } else {
                new_tail->next = curr;
                new_tail = new_tail->next;
            }
        }
        return new_head;
    }
};
