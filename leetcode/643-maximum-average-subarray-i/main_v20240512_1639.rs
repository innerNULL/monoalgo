impl Solution {
    pub fn find_max_average(nums: Vec<i32>, k: i32) -> f64 {
        let mut left: usize = 0;
        let mut right: usize = (k - 1) as usize; 
        let mut max_sum: i64 = i64::MIN;
        while right < (&nums).len() {
            let curr_sum: i64 = nums[left..=right]
                .iter()
                .map(|x| { x.clone() as i64})
                .sum();
            max_sum = std::cmp::max(max_sum, curr_sum);
            left += 1;
            right += 1;
        }
        return max_sum as f64 / k as f64;
    }
}
