/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/


inline void
init_src2copy(
    std::map<Node*, Node*>& src2copy, 
    Node* node
) {
    std::queue<Node*> queue = {};
    queue.push(node);
    while (queue.size() > 0) {
        Node* curr = queue.front();
        queue.pop();
        if (!curr) {
            continue;
        }

        for (Node* neighbor : curr->neighbors) {
            if (src2copy.find(curr) != src2copy.end()) {
                continue;
            }
            queue.push(neighbor);
            //printf("dbg: queue.size=%u\n", queue.size());
        }

        if (src2copy.find(curr) != src2copy.end()) {
            continue;
        }
        Node* copy = new Node(curr->val);
        src2copy[curr] = copy;
    }
}


inline void
init_copy2src(
    std::map<Node*, Node*>& copy2src,
    const std::map<Node*, Node*>& src2copy
) {
    for (const std::pair<Node*, Node*>& x : src2copy) {
        copy2src[x.second] = x.first;
    }
}


class Solution {
public:
    Node* cloneGraph(Node* node) {
        std::map<Node*, Node*> src2copy = {};
        std::map<Node*, Node*> copy2src = {}; 
        init_src2copy(src2copy, node);
        init_copy2src(copy2src, src2copy);
        //printf("dbg: src2copy.size=%u\n", src2copy.size());
        //printf("dbg: copy2src.size=%u\n", copy2src.size());
        std::for_each(
            copy2src.begin(), 
            copy2src.end(),
            [&copy2src, &src2copy](
                const std::pair<Node*, Node*>& x
            ) {
                for (Node* neighbor : x.second->neighbors) {
                    x.first->neighbors.emplace_back(
                        src2copy[neighbor]
                    );
                }
            }
        );
        return src2copy[node];
    }
};
