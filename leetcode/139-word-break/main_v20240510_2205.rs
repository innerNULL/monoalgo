iimpl Solution {
    pub fn word_break(s: String, word_dict: Vec<String>) -> bool {
        let mut dp: Vec<bool> = vec![false; (&s).len()];
        for i in 0..(&s).len() {
            for word in &word_dict {
                if i >= word.len() - 1 {
                    let left: usize = i - word.len() + 1;
                    let right: usize = i + 1;
                    if (
                        s[left..right].to_string() == word.to_string() 
                        && (
                            left == 0 || (&dp)[left - 1] == true
                        )
                     ) {
                        (&mut dp)[i] = true;
                    }
                }
            }
        }
        return dp.last().unwrap().clone();    
    }
}
