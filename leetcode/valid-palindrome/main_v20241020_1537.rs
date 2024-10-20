use std::collections::HashSet;


impl Solution {
    #[inline(always)]
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
        s = s
            .to_lowercase()
            .chars()
            .into_iter()
            .filter(|x: &char| { chars.contains(x) })
            .collect::<String>();
        if s.len() <= 1 {
            return true;
        }
        let mut left: usize = 0;
        let mut right: usize = s.len() - 1;
        while left < right {
            let left_val: char = s.chars().nth(left).unwrap();
            let right_val: char = s.chars().nth(right).unwrap();
            if left_val != right_val {
                return false;
            }
            left += 1;
            right -= 1;
        }
        return true;
    }
}
