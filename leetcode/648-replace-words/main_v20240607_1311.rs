use std::collections::HashSet;


impl Solution {
    pub fn replace_words(
        dictionary: Vec<String>, 
        sentence: String
    ) -> String {
        let mut prefixs: HashSet<String> = dictionary
            .into_iter()
            .collect();
        return sentence
            .split(" ")
            .map(
                |x: &str| { 
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
            .reduce(|acc: String, x: String| { acc + " " + &x })
            .unwrap();
    }
}
