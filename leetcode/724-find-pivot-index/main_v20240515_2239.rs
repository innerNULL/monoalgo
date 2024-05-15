impl Solution {
    pub fn pivot_index(nums: Vec<i32>) -> i32 {
        let mut left_sum: i32 = 0;
        let mut right_sum: i32 = (&nums).iter().sum::<i32>() - (&nums)[0];
        let mut pivot: usize = 0;
        if left_sum == right_sum {
            return pivot as i32;
        }
        while pivot < (&nums).len() - 1 {
            /*
            println!(
                "dbg: pivot={}, left_sum={}, right_sum={}", 
                pivot, left_sum, right_sum
            );
            */
            pivot += 1;
            left_sum += (&nums)[pivot - 1];
            right_sum -= (&nums)[pivot];
            if left_sum == right_sum {
                return pivot as i32;
            }
        }
        return -1;
    }
}
