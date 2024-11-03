impl Solution {
    pub fn rotate_string(s: String, goal: String) -> bool {
        if s.len() != goal.len() {
            return false;
        } 
        let s_add_s: String = s.clone() + &s;
        return s_add_s.as_str().contains(goal.as_str());
    }
}
