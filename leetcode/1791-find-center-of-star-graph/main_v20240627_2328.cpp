#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")


#include <unordered_map>
#include <vector>


class Solution {
public:
    inline int32_t 
    findCenter(std::vector<std::vector<int32_t>>& edges) {
        std::unordered_map<int32_t, size_t> recorder;
        for (const std::vector<int32_t>& edge : edges) {
            for (const int32_t& node : edge) {
                if (recorder.find(node) == recorder.end()) {
                    recorder[node] = 1;
                } else {
                    recorder[node] += 1;
                }
            }
        }
        const size_t node_cnt = recorder.size();
        for (auto const& pair : recorder) {
            if (pair.second == node_cnt - 1) {
                return pair.first;
            }
        }
        return -1;
    }
};
