class Solution {
public:
    bool validPath(
        int n, vector<vector<int>>& edges, int source, int destination
    ) {
        std::unordered_map<int32_t, std::set<int32_t>> node2nodes = {};
        for (auto& edge : edges) {
            int32_t a = edge[0];
            int32_t b = edge[1];
            if (node2nodes.find(a) == node2nodes.end()) {
                node2nodes[a] = {};
            }
            if (node2nodes.find(b) == node2nodes.end()) {
                node2nodes[b] = {};
            }
            node2nodes[a].insert(b);
            node2nodes[b].insert(a);
        }
        std::unordered_set<int32_t> recorder = {};
        std::queue<int32_t> tasks = {};
        tasks.push(source);
        while (tasks.size() > 0) {
            int32_t curr_node = tasks.front();
            tasks.pop();
            if (recorder.find(curr_node) == recorder.end()) {
                if (curr_node == destination) { return true; }
                recorder.insert(curr_node);
                for (int32_t node : node2nodes[curr_node]) {
                    tasks.push(node);
                }
            }
        }
        return false;
    }
};
