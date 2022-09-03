/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


void run_traversal(std::vector<int>& dest, Node* node) {
    if (node == NULL) { return; }
    dest.emplace_back(node->val);
    for (Node* child : node->children) {
        run_traversal(dest, child);
    }
}


class Solution {
public:
    vector<int> preorder(Node* root) {
        std::vector<int> traversal;
        run_traversal(traversal, root);
        return traversal;
    }
};