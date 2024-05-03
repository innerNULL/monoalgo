impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut max_sum: i32 = i32::MIN;
        let mut curr_sum: i32 = 0;
        for i in 0..(&nums).len() {
            curr_sum += (&nums)[i];
            max_sum = std::cmp::max(max_sum, curr_sum);
            if curr_sum < 0 {
                curr_sum = 0;
            }
        }
        return max_sum;
    }
}
