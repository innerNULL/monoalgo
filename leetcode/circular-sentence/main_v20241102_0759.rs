impl Solution {
    pub fn is_circular_sentence(sentence: String) -> bool {
        let mut out: bool = true;
        let words: Vec<String> = sentence
            .split(" ")
            .into_iter()
            .map(|x: &str| { x.to_string() })
            .collect::<Vec<String>>();
        let first: &String = &(words[0]);
        let last: &String =  &(words[words.len() - 1]);
        for i in 0..words.len() {
            if i == 0 {
                continue;
            }
            let curr: &String = &(words[i]);
            let prev: &String = &(words[i - 1]);
            if prev.chars().nth(prev.len() - 1) != curr.chars().nth(0) {
                out = false;
            } 
        }
        if last.chars().nth(last.len() - 1) != first.chars().nth(0) {
            out = false;
        }
        return out;
    }
}
