use std::sync::Mutex;


static MAGIC_NUM: Mutex<i32> = Mutex::new(i32::MAX - 100);


fn solve(
    nums: &Vec<i32>, 
    cache: &mut Vec<i32>, 
    curr_idx: usize
) -> i32 {
    if curr_idx >= nums.len() - 1 {
        if curr_idx == nums.len() - 1 {
            cache[curr_idx] = 0;
        }
        return 0;
    }
    if cache[curr_idx] != *MAGIC_NUM.lock().unwrap() {
        return cache[curr_idx];
    }
    for i in 1..=nums[curr_idx] as usize {
        cache[curr_idx] = std::cmp::min(
            cache[curr_idx], 
            solve(nums, cache, curr_idx + i) + 1
        );
    }
    return cache[curr_idx];
}


impl Solution {
    pub fn jump(nums: Vec<i32>) -> i32 {
        let mut dp: Vec<i32> = {
            vec![*MAGIC_NUM.lock().unwrap(); nums.len()]
        };
        solve(&nums, &mut dp, 0);
        return dp[0];
    }
}
