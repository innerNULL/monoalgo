impl Solution {
    pub fn is_power_of_four(n: i32) -> bool {
        if n < 1 {
            return false;
        } else if n == 4 || n == 1 {
            return true;
        } else {
            return Self::is_power_of_four(n / 4) && (n % 4 == 0);
        }
    }
}
