#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")


#include <vector>


class Solution {
public:
    inline constexpr int32_t 
    missingNumber(std::vector<int32_t>& nums) {
        int32_t out = -1;
        std::sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); ++i) {
            int32_t val = nums[i];
            if (val != static_cast<int32_t>(i)) {
                out = static_cast<int32_t>(i);
                break;
            }
        }
        if (out < 0) {
            out = nums[nums.size() - 1] + 1;
        }
        return out;
    }
};
