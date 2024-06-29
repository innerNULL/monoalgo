use std::collections::HashSet;


impl Solution {
    #[inline(always)]
    pub fn can_be_typed_words(
        text: String, 
        broken_letters: String
    ) -> i32 {
        let brokens: HashSet<char> = broken_letters
            .chars()
            .collect::<HashSet<char>>();
        return text
            .split(" ")
            .map(
                |x: &str| {
                    for c in x.chars() {
                        if (&brokens).contains(&c) {
                            return 0;
                        }
                    }
                    return 1;
                }
            )
            .sum();
    }
}
