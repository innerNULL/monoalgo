#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")


int32_t solve(
    const std::vector<int32_t>& nums, 
    std::vector<int32_t>& dp, 
    size_t i
) {
    if (i >= nums.size()) {
        return 0;
    }
    if (dp[i] != -1) {
        return dp[i];
    }
    dp[i] = std::max(
        solve(nums, dp, i + 1),
        nums[i] + solve(nums, dp, i + 2)
    );
    return dp[i];
}


class Solution {
public:
    int rob(vector<int>& nums) {
        std::vector<int32_t> dp(nums.size(), -1);
        return solve(nums, dp, 0);
    }
};
