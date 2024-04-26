impl Solution {
    pub fn h_index(mut citations: Vec<i32>) -> i32 {
        citations.sort();
        citations = citations
            .iter()
            .filter(|&n| {*n != 0})
            .copied()
            .collect();
        let cnt: usize = citations.len();
        for i in 0..cnt {
            if (cnt - i) as i32 <= citations[i] {
                return (cnt - i) as i32;
            }
        }
        return 0;
    }
}
