use std::collections::HashSet;


impl Solution {
    pub fn number_of_special_chars(word: String) -> i32 {
        let mut cnt: i32 = 0;
        let mut upper: HashSet<char> = HashSet::new();
        let mut lower: HashSet<char> = HashSet::new();
        for c in word.chars() {
            if c.is_uppercase() {
                let lower_c: char = c
                    .to_lowercase()
                    .collect::<String>()
                    .chars()
                    .nth(0)
                    .unwrap();
                if lower.contains(&lower_c) && !upper.contains(&c) {
                    cnt += 1;
                }
                upper.insert(c);
            }
            if c.is_lowercase() {
                let upper_c: char = c
                    .to_uppercase()
                    .collect::<String>()
                    .chars()
                    .nth(0)
                    .unwrap();
                if upper.contains(&upper_c) && !lower.contains(&c) {
                    cnt += 1;
                }
                lower.insert(c);
            }
        }
        return cnt;
    }
}
