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


typedef struct LinkedList {
    ListNode* head = NULL;
    ListNode* tail = NULL;
    int32_t size = 0;
} LinkedList;


inline void linkedlist_insert(LinkedList* list, ListNode* node) {
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = list->head;
    } else {
        list->tail->next = node;
        list->tail = list->tail->next;
    }
    list->size++;
}


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL) { return head; }
        LinkedList* smaller = new LinkedList();
        LinkedList* larger = new LinkedList();
        ListNode* reader = head;
        while (reader) {
            ListNode* reader_next = reader->next;
            if (reader->val < x) {
                linkedlist_insert(smaller, reader);
            } else {
                linkedlist_insert(larger, reader);
            }
            reader = reader_next;
        }
        if (smaller->size > 0) {
            if (larger->size > 0) {
                smaller->tail->next = larger->head;
            }
            return smaller->head;
        } else {
            return larger->head;
        }
    }
};
