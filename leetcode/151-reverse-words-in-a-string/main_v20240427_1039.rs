unsafe fn reverse_substr(
    s: &mut String, mut left_idx: usize, mut right_idx: usize
) {
    let mut c_ptr: *mut u8 = s.as_mut_ptr();
    while left_idx < right_idx {
        let left_val: char = s.chars().nth(left_idx).unwrap();
        let right_val: char = s.chars().nth(right_idx).unwrap();
        *(c_ptr.add(left_idx)) = right_val as u8;
        *(c_ptr.add(right_idx)) = left_val as u8;
        left_idx += 1;
        right_idx -= 1;
    }
}


impl Solution {
    pub fn reverse_words(mut s: String) -> String {
        let size: usize = s.len();
        let mut left_idx: usize = 0;
        let mut right_idx: usize = 0;
        unsafe { reverse_substr(&mut s, 0, size - 1); }
        while right_idx < s.len() {
            //println!("dbg: left_idx={}, right_idx={}", left_idx, right_idx);
            right_idx = left_idx + 1;
            while right_idx < s.len() 
              && s.chars().nth(right_idx).unwrap() != ' ' 
            {
                right_idx += 1;
            }
            unsafe {
                reverse_substr(&mut s, left_idx, right_idx - 1);
            }
            left_idx = right_idx;
            while left_idx < s.len() 
                && s.chars().nth(left_idx).unwrap() == ' ' 
            {
                left_idx += 1;
            }
        }
        let mut first_not_space_idx: usize = 0;
        let mut last_not_space_idx: usize = s.len() - 1;
        while first_not_space_idx < s.len() {
            if s.chars().nth(first_not_space_idx).unwrap() != ' ' {
                break;
            }
            first_not_space_idx += 1;
        }
        while last_not_space_idx >= first_not_space_idx {
            if s.chars().nth(last_not_space_idx).unwrap() != ' ' {
                break;
            }
            last_not_space_idx -= 1;
        }
        let chars: Vec<char> = s.chars().collect();
        let mut filtered_chars: Vec<char> = Vec::new();
        for i in first_not_space_idx..=last_not_space_idx {
            if i > 0 && chars[i] == ' ' && chars[i - 1] == ' ' {
                continue;
            }
            filtered_chars.push(chars[i]);
        }
        //return s[first_not_space_idx..=last_not_space_idx].to_string();
        return filtered_chars.iter().collect();
    }
}
