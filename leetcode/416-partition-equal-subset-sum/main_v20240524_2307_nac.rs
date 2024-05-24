#[inline]
fn solve(
    nums: &Vec<i32>, 
    index: usize, 
    sum1: i32, 
    sum2: i32
) -> bool {
    if index >= nums.len() {
        return sum1 == sum2;
    } else {
        return (
            solve(nums, index + 1, sum1 + nums[index], sum2)
            || solve(nums, index + 1, sum1, sum2 + nums[index])
        );
    }
}


impl Solution {
    pub fn can_partition(nums: Vec<i32>) -> bool {
        return solve(&nums, 0, 0, 0);   
    }
}
