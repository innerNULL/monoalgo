#include <vector>

using std::vector;


inline constexpr bool 
dfs(
    const size_t idx, 
    const vector<int32_t>& nums,
    vector<int32_t>& cache
) {
    if (cache[idx] != -1) {
        return cache[idx] == 1 ? true : false;
    }
    bool result = false;
    for (size_t i = 1;  i <= nums[idx]; ++i) {
        const size_t next_idx = idx + i;
        if (next_idx >= nums.size() - 1) {
            result = true;
            break;
        }
        result = result || dfs(idx + i, nums, cache);
    }
    cache[idx] = result ? 1 : 0;
    return result;
}


class Solution {
public:
    inline constexpr bool 
    canJump(const vector<int32_t>& nums) {
        vector<int32_t> cache(nums.size(), -1);
        if (nums.size() <= 1) { return true; }
        for (size_t i = 0; i < nums.size(); ++i) {
            dfs(i, nums, cache);
        }
        return cache[0];
    }
};
