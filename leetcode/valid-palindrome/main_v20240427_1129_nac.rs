use std::collections::HashSet;


impl Solution {
    pub fn is_palindrome(mut s: String) -> bool {
        let chars: HashSet<char> = HashSet::from_iter(
            [
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 
                'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 
                'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 
                'y', 'z',
                '0', '1', '2', '3', '4', '5', '6', '7', 
                '8', '9'
            ]
        );
        s = s.to_lowercase();
        let mut left_idx = 0;
        let mut right_idx = s.len() - 1;
        //println!("dbg: left_idx={}, right_idx={}", left_idx, right_idx);
        while left_idx < right_idx {
            //println!("dbg: left_idx={}, right_idx={}", left_idx, right_idx);
            if (right_idx as i32) < 0 || left_idx >= s.len() 
                || left_idx == right_idx 
            { 
                break; 
            }
            while left_idx < right_idx
                && !chars.contains(&s.chars().nth(left_idx).unwrap())
            {
                //println!("dbg: left_idx={}, right_idx={}", left_idx, right_idx);
                left_idx += 1;
            }
            while right_idx > left_idx 
                && !chars.contains(&s.chars().nth(right_idx).unwrap())
            {
                right_idx -= 1;
            }
            if s.chars().nth(left_idx).unwrap() != s.chars().nth(right_idx).unwrap() 
            {
                return false;
            }
            left_idx += 1;
            right_idx -= 1;
        }
        return true;
    }
}
