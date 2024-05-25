impl Solution {
    pub fn find_duplicates(mut nums: Vec<i32>) -> Vec<i32> {
        let mut out: Vec<i32> = Vec::new();
        nums.sort(); 
        for i in 1..nums.len() {
            if (&nums)[i] == (&nums)[i - 1] {
                out.push((&nums)[i]);
            }
        }
        return out;
    }
}
