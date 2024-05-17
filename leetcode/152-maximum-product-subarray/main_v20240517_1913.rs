impl Solution {
    pub fn max_product(nums: Vec<i32>) -> i32 {
        let mut dp_max: Vec<i32> = vec![0; (&nums).len()];
        let mut dp_min: Vec<i32> = vec![0; (&nums).len()];
        (&mut dp_max)[0] = (&nums)[0];
        (&mut dp_min)[0] = (&nums)[0];
        let mut max_prod: i32 = (&nums)[0];
        let mut max_last: i32 = (&nums)[0];
        let mut min_last: i32 = (&nums)[0];
        //println!("dbg: max_last={}, min_last={}", max_last, min_last);
        for i in 1..(&nums).len() {
            let curr_val: i32 = (&nums)[i];
            //println!("dbg: nums[i]={}", curr_val);
            max_last = std::cmp::max(
                std::cmp::max(curr_val, (&dp_max)[i - 1] * curr_val),
                (&dp_min)[i - 1] * curr_val
            );
            min_last = std::cmp::min(
                std::cmp::min(curr_val, (&dp_max)[i - 1] * curr_val),
                (&dp_min)[i - 1] * curr_val
            );
            (&mut dp_max)[i] = max_last;
            (&mut dp_min)[i] = min_last;
            max_prod = std::cmp::max(max_prod, max_last);
            //println!("dbg: max_last={}, min_last={}", max_last, min_last);
        }
        return max_prod;
    }
}
