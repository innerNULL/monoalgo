impl Solution {
    pub fn majority_element(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        return nums[nums.len() / 2];
    }
}
