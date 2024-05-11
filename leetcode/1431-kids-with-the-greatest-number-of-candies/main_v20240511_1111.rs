impl Solution {
    pub fn kids_with_candies(
        candies: Vec<i32>, extra_candies: i32
    ) -> Vec<bool> {
        let max: i32 = candies.iter().max().unwrap().clone();
        let mut out: Vec<bool> = vec![false; (&candies).len()];
        candies.iter().enumerate().for_each(|(i, x)| {
            if x + extra_candies >= max {
                (&mut out)[i] = true;
            }
        });
        return out;
    }
}
