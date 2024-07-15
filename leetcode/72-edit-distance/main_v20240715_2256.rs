impl Solution {
    #[inline(always)]
    pub fn min_distance(word1: String, word2: String) -> i32 {
        let len1: usize = word1.len();
        let len2: usize = word2.len();
        // dp[0..=n][0..=m] represents edit distance between
        // word1[0..=n] and word2[0..=m].
        let mut dp: Vec<Vec<i32>> = vec![
            vec![-1; len2 + 1]; len1 + 1
        ];
        dp[0][0] = 0;
        (1..=len1)
            .for_each(|row: usize| {
                dp[row][0] = row as i32;
            });
        (1..=len2)
            .for_each(|col: usize| {
                dp[0][col] = col as i32;
            });
        (1..=len1)
            .for_each(|row: usize| {
                (1..=len2)
                    .for_each(|col: usize| {
                        let char1: char = word1
                            .chars()
                            .nth(row - 1)
                            .unwrap();
                        let char2: char = word2
                            .chars()
                            .nth(col - 1)
                            .unwrap();
                        if char1 == char2 {
                            dp[row][col] = dp[row - 1][col - 1];
                        } else {
                            dp[row][col] = {
                                std::cmp::min(
                                    std::cmp::min(
                                        dp[row - 1][col], dp[row][col - 1]
                                    ),
                                    dp[row - 1][col - 1]
                                ) + 1
                            };
                        }
                    });
            });
        return dp[len1][len2];
    }
}
