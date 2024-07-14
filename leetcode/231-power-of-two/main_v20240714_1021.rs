impl Solution {
    #[inline(always)]
    pub fn is_power_of_two(n: i32) -> bool {
        if n == 0 {
            return false;
        } else if n == 1 || n == 2 {
            return true;
        } else if n % 2 != 0 {
            return false;
        } else {
            return Solution::is_power_of_two(n / 2);
        }
    }
}
