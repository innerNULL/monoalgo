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

std::tuple<ListNode*, ListNode*> 
sublist_reverse(ListNode* head, ListNode* tail) {
    if (head == tail) { 
        return std::make_tuple(head, tail); 
    }
    ListNode* dummy_head = new ListNode();
    ListNode* dummy_tail = dummy_head; 
    ListNode* node = head;
    while (node != tail) {
        if (dummy_head->next == nullptr) {
            dummy_head->next = node;
            dummy_tail = node;
            node = node->next;
        } else {
            ListNode* old_next = dummy_head->next;
            dummy_head->next = node;
            node = node->next;
            dummy_head->next->next = old_next;
        }
    }
    node->next = dummy_head->next;
    dummy_head->next = node;

    head = dummy_head->next;
    tail = dummy_tail;
    tail->next = nullptr;
    /*
    ListNode* tmp = head;
    while (tmp != tail) {
        printf("dbg %i\n", tmp->val);
        tmp = tmp->next;
    }
    printf("dbg %i\n", tmp->val);
    printf("haha\n");
    printf("Finished one time's reverse\n");
    */
    return std::make_tuple(head, tail);
}


void get_nodes_which_idx_is_divisible_by_k(
    std::vector<ListNode*>* dest, ListNode* head, int32_t k
) {
    dest->clear();
    ListNode* node = head;
    int32_t idx = 0;
    while (node) {
        if (idx % k == 0) {
            dest->emplace_back(node);
        } else if (node->next == nullptr) {
            break;
        }
        node = node->next;
        idx++;
    }
}


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) {
            return head;
        }

        std::vector<ListNode*> group_heads;
        std::vector<ListNode*> group_tails;
        ListNode* group_head = head;
        ListNode* group_tail = head;

        int32_t cnt = k - 1;
        while (cnt > 0 && group_tail->next) {
            group_tail = group_tail->next;
            cnt--;
        }

        get_nodes_which_idx_is_divisible_by_k(
            &group_heads, group_head, k
        );
        get_nodes_which_idx_is_divisible_by_k(
            &group_tails, group_tail, k
        );

        // debug
        /*
        printf("k=%i\n", k);
        printf("head nodes:\n");
        for (ListNode* node : group_heads) {
            printf("%i ", node->val);
        }
        printf("\ntail nodes:\n");
        for (ListNode* node : group_tails) {
            printf("%i ", node->val);
        }
        printf("\n");
        /*/

        for (int32_t i = 0; i < group_tails.size(); ++i) {
            std::tie(group_heads[i], group_tails[i]) = sublist_reverse(
                group_heads[i], group_tails[i]
            );
        }
        for (int32_t i = 0; i < group_tails.size(); ++i) {
            if ( (i + 1) < group_heads.size()) {
                group_tails[i]->next = group_heads[i + 1];
            }
        }
        return group_heads[0];
    }
};
