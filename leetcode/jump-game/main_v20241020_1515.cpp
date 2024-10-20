#include <vector>


inline constexpr bool
dfs(
    const size_t idx, 
    const std::vector<int32_t>& nums,
    std::vector<int8_t>& cache
) {
    if (idx >= nums.size()) { return false; }
    if (idx == nums.size() - 1) { return true; }
    if (cache[idx] != -1) {
        return cache[idx] == 1 ? true : false;
    }
    bool out = false;
    for (size_t i = 1; i <= nums[idx]; ++i) {
        bool next_out = dfs(idx + i, nums, cache);
        if (next_out) {
            out = true;
            break;
        }
    }
    cache[idx] = out ? 1 : 0;
    return out;
}


class Solution {
public:
    inline constexpr bool 
    canJump(std::vector<int32_t>& nums) {
        std::vector<int8_t> cache(nums.size(), -1);
        for (size_t i = nums.size() - 1; i-- > 0; ) {
            dfs(i, nums, cache);
        }
        return cache[0];
    }
};
