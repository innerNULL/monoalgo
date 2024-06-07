use std::collections::HashSet;


impl Solution {
    pub fn replace_words(
        dictionary: Vec<String>, 
        sentence: String
    ) -> String {
        let mut prefixs: HashSet<String> = dictionary
            .into_iter()
            .collect();
        let mut out: Vec<String> = sentence
            .split(" ")
            .collect::<Vec<&str>>()
            .iter()
            .map(
                |x: &&str| { 
                    let word: String = (*x).to_string();
                    for i in 1..=word.len() {
                        let curr_prefix: String = word[0..i].to_string();
                        if prefixs.contains(&curr_prefix) {
                            return curr_prefix;
                        }
                    }
                    return word;
                }
            )
            .collect::<Vec<String>>();
        return out
            .into_iter()
            .reduce(|acc: String, x: String| { acc + " " + &x })
            .unwrap();
    }
}
