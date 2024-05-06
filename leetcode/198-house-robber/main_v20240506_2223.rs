fn solve(nums: &Vec<i32>, dp: &mut Vec<i32>, at: usize) -> i32 {
    if at >= nums.len() {
        return 0;
    }
    if dp[at] != -1 {
        return dp[at];
    }
    dp[at] = std::cmp::max(
        nums[at] + solve(nums, dp, at + 2), 
        solve(nums, dp, at + 1)
    );
    return dp[at]
}


impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let mut dp: Vec<i32> = vec![-1; nums.len()];
        return solve(&nums, &mut dp, 0);
    }
}
