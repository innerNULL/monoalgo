impl Solution {
    pub fn make_fancy_string(s: String) -> String {
        let mut out_chars: Vec<char> = Vec::new();
        s.chars()
            .into_iter()
            .enumerate()
            .for_each(
                |x: (usize, char)| { 
                    if x.0 <= 1 {
                        out_chars.push(x.1);
                    } else if (
                        x.1 != out_chars[out_chars.len() - 1]
                        || x.1 != out_chars[out_chars.len() - 2]
                    ) {
                        out_chars.push(x.1);
                    }
                }
            );
        return out_chars
            .into_iter()
            .collect::<String>();
    }
}
