impl Solution {
    #[inline(always)]
    pub fn remove_stars(s: String) -> String {
        let mut stack: Vec<char> = Vec::new();
        for c in s.chars() {
            if c == '*' {
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        return stack.into_iter().collect::<String>();
    }
}
