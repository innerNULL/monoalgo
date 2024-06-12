use std::collections::HashSet;


impl Solution {
    #[inline(always)]
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut out: Vec<String> = Vec::new();
        for i in 0..n as usize {
            if out.len() == 0 {
                out.push("()".to_string());
            } else {
                let mut new: Vec<String> = Vec::new();
                for s in &out {
                    for j in 0..s.len() {
                        if j == 0 {
                            new.push(
                                "()".to_string() + &s
                            );
                        }
                        if j == s.len() - 1 {
                            new.push(
                                s.clone() + "()"
                            );
                        }
                        if s.chars().nth(j).unwrap() == '(' {
                            new.push(
                                s[0..=j].to_string() 
                                + "()"
                                + &s[j + 1..s.len()]
                            );
                        }
                    }
                }
                out = new;
            }
        }
        return out
            .into_iter()
            .collect::<HashSet<String>>()
            .into_iter()
            .collect::<Vec<String>>();
    }
}
