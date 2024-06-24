#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")


#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>


class Solution {
public:
    inline std::vector<std::string> 
    findRelativeRanks(std::vector<int32_t>& score) {
        std::unordered_map<int32_t, size_t> ranks = {};
        {
            std::vector<int32_t> sorted_score = score;
            std::sort(
                sorted_score.begin(), 
                sorted_score.end(), 
                [](const int32_t& a, const int32_t& b) {
                    return a > b;
                }
            );
            size_t i = 1;
            for (const int32_t& x : sorted_score) {
                ranks[x] = i;
                i += 1;
            }
        }
        std::vector<std::string> out = {};
        for (const int32_t& x : score) {
            const size_t rank = ranks[x];
            if (rank == 1) {
                out.emplace_back("Gold Medal");
            } else if (rank == 2) {
                out.emplace_back("Silver Medal");
            } else if (rank == 3) {
                out.emplace_back("Bronze Medal");
            } else {
                out.emplace_back(std::to_string(rank));
            }
        }
        return out;
    }
};
