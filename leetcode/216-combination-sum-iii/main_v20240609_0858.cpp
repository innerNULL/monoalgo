#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")


inline void 
solve(
    std::vector<std::vector<int32_t>>& dest,
    std::vector<int32_t>& buffer, 
    int32_t k, 
    int32_t n, 
    size_t curr_num
) {
    if (buffer.size() == static_cast<size_t>(k)) {
        if (std::accumulate(buffer.begin(), buffer.end(), 0) == n) {
            dest.emplace_back(buffer);
        }
        return;
    }
    if (curr_num > 9) {
        return;
    }
    buffer.emplace_back(curr_num);
    solve(dest, buffer, k, n, curr_num + 1);
    buffer.pop_back();
    solve(dest, buffer, k, n, curr_num + 1);
    return;
}


class Solution {
public:
    inline 
    std::vector<std::vector<int32_t>> 
    combinationSum3(
        int32_t k, 
        int32_t n
    ) {
        std::vector<std::vector<int32_t>> out;
        std::vector<int32_t> buffer;
        solve(out, buffer, k, n, 1);
        return out;
    }
};
