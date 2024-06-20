use std::collections::HashMap;
use std::cmp::Ordering;


impl Solution {
    #[inline(always)]
    pub fn frequency_sort(s: String) -> String {
        let mut char_freq: Vec<(char, i32)> = {
            let mut char2freq: HashMap<char, i32> = HashMap::new();
            for c in s.chars() {
                let mut entry: Option<&mut i32> = char2freq.get_mut(&c);
                match entry {
                    None => {
                        char2freq.insert(c, 1);
                    },
                    Some(x) => {
                        *x += 1;
                    }
                }
            }
            char2freq
                .into_iter()
                .collect::<Vec<(char, i32)>>()
        };
        char_freq.sort_by(
            |a: &(char, i32), b: &(char, i32)| {
                if a.1 > b.1 {
                    return Ordering::Less;
                } else if a.1 < b.1 {
                    return Ordering::Greater;
                } else {
                    return Ordering::Equal;
                }
            }
        );
        return char_freq
            .into_iter()
            .map(
                |x: (char, i32)| {
                    let mut out: Vec<char> = Vec::new();
                    for i in 0..x.1 {
                        out.push(x.0);
                    }
                    return out.into_iter().collect::<String>();
                }
            )
            .collect::<String>();
    }
}
