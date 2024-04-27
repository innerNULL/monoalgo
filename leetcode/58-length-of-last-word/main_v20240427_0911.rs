impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let mut right_idx: usize = s.len() - 1;
        while right_idx as i32 >= 0 {
            if (&s).chars().nth(right_idx).unwrap() != ' ' {
                break;
            } else {
                right_idx -= 1;
            }
        }
        let mut left_idx: usize = right_idx - 1;
        while left_idx as i32 >= 0 {
            if (&s).chars().nth(left_idx).unwrap() == ' ' {
                break;
            } else {
                left_idx -= 1;
            }
        }
        return right_idx as i32 - left_idx as i32;
    }
}
