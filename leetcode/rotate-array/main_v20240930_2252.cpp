#include <vector>


inline constexpr void
rotate_by_idx(
    std::vector<int32_t>& nums,
    const size_t start_idx, 
    const size_t end_idx
) {
    size_t left = start_idx;
    size_t right = end_idx;
    while (left < right) {
        int32_t tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left += 1;
        right -= 1;
    }
    return;
}


class Solution {
public:
    inline constexpr void 
    rotate(std::vector<int32_t>& nums, int32_t k) {
        k = k % nums.size();
        const size_t len = nums.size();
        if (len <= k || k < 1) { return; }
        rotate_by_idx(nums, 0, nums.size() - 1);
        rotate_by_idx(nums, 0, k - 1);
        rotate_by_idx(nums, k, nums.size() - 1);
        return;
    }
};
