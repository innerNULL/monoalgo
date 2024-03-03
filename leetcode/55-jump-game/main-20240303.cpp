/* Solution 1: Time Limit Exceeded:

bool not_blocked(
    const std::vector<int32_t>& nums, int32_t curr_idx
) {
    if (curr_idx == nums.size() - 1) { return true; }
    if (nums[curr_idx] == 0) { return false; }

    int32_t max_steps = nums[curr_idx];
    for (int32_t i = curr_idx + 1; i <= curr_idx + max_steps; ++i) {
        if (i < nums.size() && not_blocked(nums, i)) {
            return true;
        }
    }
    return false;
}


class Solution {
public:
    bool canJump(vector<int>& nums) {
        return not_blocked(nums, 0);
    }
};
*/


bool not_blocked(
    const std::vector<int32_t>& nums, int32_t curr_idx,
    std::vector<int8_t>& cache
) {
    if (curr_idx == nums.size() - 1) { return true; }
    if (nums[curr_idx] == 0) { return false; }
    if (cache[curr_idx] == 1) { return true; }
    if (cache[curr_idx] == 0) { return false; }

    int32_t max_steps = nums[curr_idx];
    for (int32_t i = curr_idx + 1; i <= curr_idx + max_steps; ++i) {
        if (i < nums.size() && not_blocked(nums, i, cache)) {
            cache[curr_idx] = 1;
            return true;
        }
    }
    cache[curr_idx] = 0;
    return false;
}


class Solution {
public:
    bool canJump(vector<int>& nums) {
        std::vector<int8_t> cache(nums.size(), -1);
        return not_blocked(nums, 0, cache);
    }
};
