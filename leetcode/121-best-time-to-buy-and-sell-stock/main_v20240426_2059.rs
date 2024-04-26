use std::cmp;


impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut right_max: Vec<i32> = vec![0; prices.len()];
        for i in 0..(prices.len() - 1) {
            let idx: usize = prices.len() - 2 - i;
            right_max[idx] = cmp::max(prices[idx + 1], right_max[idx + 1]);
            //println!("dbg: right_max[{}]={}", idx, right_max[idx]);
        }
        return right_max
            .iter()
            .zip(prices.iter())
            .map(|(a, b)| { cmp::max(a - b, 0) })
            .max()
            .unwrap(); 
    }
}
