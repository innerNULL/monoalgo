impl Solution {
    pub fn max_operations(mut nums: Vec<i32>, k: i32) -> i32 {
        let mut cnt: i32 = 0;
        nums.sort();
        let mut left: usize = 0;
        let mut right: usize = (&nums).len() - 1;
        while left < right {
            let sum: i32 = (&nums)[left] + (&nums)[right];
            if sum < k {
                left += 1;
            } else if sum > k {
                right -= 1;
            } else {
                cnt += 1;
                left += 1;
                right -= 1;
            }
        }
        return cnt;
    }
}
