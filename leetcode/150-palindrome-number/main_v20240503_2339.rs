impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 {
            return false;
        }
        let num_chars: Vec<char> = x.to_string().chars().collect();
        let mut left_idx: usize = 0;
        let mut right_idx: usize = (&num_chars).len() - 1;
        while left_idx < right_idx {
            if (&num_chars)[left_idx] != (&num_chars)[right_idx] {
                return false;
            }
            left_idx += 1;
            right_idx -= 1;
        }
        return true;
    }
}
