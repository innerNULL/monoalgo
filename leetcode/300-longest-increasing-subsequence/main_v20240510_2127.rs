impl Solution {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        match (&nums).len() {
            0 => {
                return 0;
            },
            _ => {
                let mut dp: Vec<i32> = vec![1; (&nums).len()];
                for i in 1..(&nums).len() {
                    for j in 0..i {
                        if (&nums)[j] < (&nums)[i] {
                            (&mut dp)[i] = std::cmp::max(
                                (&dp)[i], (&dp)[j] + 1
                            );
                        }
                    }
                }
                return dp.iter().max().unwrap().clone();
            }
        }
    }
}
