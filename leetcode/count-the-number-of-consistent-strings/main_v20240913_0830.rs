use std::collections::HashSet;


impl Solution {
    #[inline(always)]
    pub fn count_consistent_strings(
        allowed: String, 
        words: Vec<String>
    ) -> i32 {
        let mut cnt: i32 = 0;
        let targets: HashSet<char> = allowed
            .chars()
            .into_iter()
            .collect::<HashSet<char>>();
        words
            .into_iter()
            .for_each(
                |x: String| {
                    let mut consistent: bool = true;
                    for c in x.chars() {
                        if !targets.contains(&c) {
                            consistent = false;
                            break;
                        }   
                    }
                    if consistent == true {
                        cnt += 1;
                    }
                }
            );
        return cnt; 
    }
}
