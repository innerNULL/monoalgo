use std::collections::HashMap;


impl Solution {
    #[inline(always)]
    pub fn first_uniq_char(s: String) -> i32 {
        let mut out: i32 = -1;
        let mut recorder: HashMap<char, i32> = HashMap::new();
        for c in s.chars() {
            let entry: Option<&mut i32> = recorder.get_mut(&c);
            match entry {
                None => {
                    recorder.insert(c, 1);
                },
                Some(x) => {
                    *x += 1;
                }
            }
        }
        for (i, c) in s.chars().enumerate() {
            let cnt: i32 = *recorder.get(&c).unwrap();
            if cnt == 1 {
                out = i as i32;
                break;
            }

        }
        return out;
    }
}
