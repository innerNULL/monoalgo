use std::cmp::min;


impl Solution {
    pub fn min_distance(word1: String, word2: String) -> i32 {
        let size1: usize = word1.len();
        let size2: usize = word2.len();
        let mut dp: Vec<Vec<i32>> = vec![vec![0; size2 + 1]; size1 + 1];
        for i in 0..(size1 + 1) as usize { dp[i][0] = (i as i32); }
        for j in 0..(size2 + 1) as usize { dp[0][j] = (j as i32); }
        for i in 1..(size1 + 1) as usize {
            for j in 1..(size2 + 1) as usize {
                if (&word1).chars().nth(i - 1) == (&word2).chars().nth(j - 1) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(
                        dp[i - 1][j - 1], 
                        min(dp[i - 1][j], dp[i][j - 1])
                    ) + 1;
                }
            }
        }
        return dp[size1][size2];
    }
}
