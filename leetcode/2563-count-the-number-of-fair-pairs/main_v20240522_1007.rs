impl Solution {
    pub fn count_fair_pairs(
        mut nums: Vec<i32>, lower: i32, upper: i32
    ) -> i64 {
        let mut cnt: i64 = 0;
        nums.sort();
        let mut reader: usize = 0;
        while reader < (&nums).len() - 1 {
            let left_val: i32 = unsafe { *(&nums).get_unchecked(reader) };
            let right: &[i32] = &(&nums)[reader + 1..];
            let right_l_bound: usize = right
                .partition_point(|x| x + left_val < lower);
            let right_r_bound: usize = right
                .partition_point(|x| x + left_val <= upper);
            reader += 1;
            cnt += (right_r_bound - right_l_bound) as i64;
        }
        return cnt;
    }
}
