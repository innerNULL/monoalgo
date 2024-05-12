use std::collections::HashSet;
use std::fmt::Display;


lazy_static! {
    static ref VOWELS: HashSet<char> = {
        let mut set: HashSet<char> = HashSet::new();
        set.insert('a');
        set.insert('e');
        set.insert('i');
        set.insert('o');
        set.insert('u');
        set.insert('A');
        set.insert('E');
        set.insert('I');
        set.insert('O');
        set.insert('U'); 
        set
    };
}


impl Solution {
    pub fn max_vowels(s: String, k: i32) -> i32 {
        let mut left: usize = 0;
        let mut right: usize = k as usize - 1;
        let mut max_vowels_cnt: usize = 0;
        let mut curr_vowels_cnt: usize = s[left..=right]
            .chars()
            .filter(|x| { VOWELS.contains(x) } )
            .map(|x| { 1 as usize })
            .sum();
        while right < (&s).len() - 1 {
            //println!("dbg: left={}, right={}", left, right);
            if (&VOWELS).contains(&(&s).chars().nth(left).unwrap()) {
                curr_vowels_cnt -= 1;
            }
            if (&VOWELS).contains(&(&s).chars().nth(right + 1).unwrap()) {
                curr_vowels_cnt += 1;
            }
            max_vowels_cnt = std::cmp::max(
                max_vowels_cnt, curr_vowels_cnt
            );
            left += 1;
            right += 1;
        }
        return max_vowels_cnt as i32;
    }
}
