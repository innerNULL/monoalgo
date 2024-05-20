impl Solution {
    pub fn add_digits(num: i32) -> i32 {
        let mut digits: Vec<i32> = Vec::new();
        let mut divisor: i32 = 10;
        let mut curr: i32 = num;
        while curr > 0 {
            let remainder: i32 = curr % divisor;
            curr /= divisor;
            divisor *= 10;
            digits.push(remainder);
        }
        let cand: i32 = digits.iter().sum();
        if cand < 10 {
            return cand;
        } else {
            return Self::add_digits(cand);
        }
    }
}
