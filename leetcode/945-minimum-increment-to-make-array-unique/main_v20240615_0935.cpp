#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")


class Solution {
public:
    inline int32_t 
    minIncrementForUnique(std::vector<int32_t>& nums) {
        int32_t moves = 0;
        std::sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i] <= nums[i - 1]) {
                const int32_t new_val = nums[i - 1] + 1;
                moves += (new_val - nums[i]);
                nums[i] = new_val;
            }
        }
        return moves;
    }
};
