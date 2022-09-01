/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


ListNode* get_cycle_node(ListNode* head) {
    ListNode* cycle_node = NULL;
    ListNode* faster_ptr = head;
    ListNode* slower_ptr = head;
    while (faster_ptr) {
        faster_ptr = faster_ptr->next;
        if (faster_ptr == NULL) { break; }
        faster_ptr = faster_ptr->next;
        slower_ptr = slower_ptr->next;
        
        if (faster_ptr == slower_ptr) { 
            cycle_node = faster_ptr; 
            break;
        }
    }
    return cycle_node;
}


int32_t get_cycle_size(ListNode* cycle_node) {
    ListNode* faster_ptr = cycle_node;
    ListNode* slower_ptr = cycle_node;
    
    int32_t count = 0;
    while (true) {
        faster_ptr = faster_ptr->next->next;
        slower_ptr = slower_ptr->next;
        count += 1;
        if (faster_ptr == slower_ptr) { break; }
    } 
    return count;
}
    

ListNode* get_cycle_start(ListNode *head, int32_t cycle_size) {
    ListNode* faster_ptr = head;
    ListNode* slower_ptr = head;
    
    int32_t pre_steps = cycle_size;
    while (pre_steps > 0) { 
        faster_ptr = faster_ptr->next; 
        pre_steps -= 1;
    }
    while (faster_ptr != slower_ptr) {
        faster_ptr = faster_ptr->next;
        slower_ptr = slower_ptr->next;
    }
    return slower_ptr;
}


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* cycle_start_node = NULL;
        ListNode* cycle_node = get_cycle_node(head);
        if (cycle_node) {
            int32_t cycle_size = get_cycle_size(cycle_node);
            //printf("dbg: cycle_size=%i\n", cycle_size);
            cycle_start_node = get_cycle_start(head, cycle_size);
        }
        return cycle_start_node;
    }
};