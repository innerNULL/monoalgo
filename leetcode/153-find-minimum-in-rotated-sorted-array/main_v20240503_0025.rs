impl Solution {
    pub fn find_min(nums: Vec<i32>) -> i32 {
        if (&nums[0]) <= (&nums).last().unwrap() {
            return (&nums)[0];
        }
        let mut left_idx: usize = 0;
        let mut right_idx: usize = (&nums).len() - 1;
        let mut min_idx: usize = right_idx;
        while left_idx < right_idx - 1 {
            //println!("dbg: left_idx={}, right_idx={}", left_idx, right_idx);
            let mid_idx: usize = (left_idx + right_idx) / 2;
            let mid_val: i32 = (&nums)[mid_idx];
            let left_val: i32 = (&nums)[left_idx];
            let right_val: i32 = (&nums)[right_idx];
            if mid_val > left_val {
                left_idx = mid_idx;
            } else if mid_val < right_val {
                min_idx = mid_idx;
                right_idx -= 1;
            }
        }
        return (&nums)[min_idx];
    }
}
