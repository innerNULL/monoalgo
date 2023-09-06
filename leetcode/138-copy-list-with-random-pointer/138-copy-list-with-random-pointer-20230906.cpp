/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* node = head;
        std::unordered_map<Node*, Node*> origin2clone = {};
        while (node) {
            Node* clone = new Node(node->val);
            origin2clone[node] = clone;
            node = node->next;
        }
        node = head;
        while (node) {
            Node* clone = origin2clone[node];
            clone->next = origin2clone[node->next];
            clone->random = origin2clone[node->random];
            node = node->next;
        }
        return origin2clone[head];
    }
};
