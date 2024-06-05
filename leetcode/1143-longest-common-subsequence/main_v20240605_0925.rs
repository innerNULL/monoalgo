impl Solution {
    #[inline(always)]
    pub fn longest_common_subsequence(
        text1: String, 
        text2: String
    ) -> i32 {
        let mut longer: String = String::new();
        let mut shorter: String = String::new();
        let len1: usize = text1.len();
        let len2: usize = text2.len();
        if len1 < len2 {
            longer = text2;
            shorter = text1;
        } else {
            longer = text1;
            shorter = text2;
        }
        let mut dp: Vec<Vec<i32>> = vec![
            vec![0; longer.len() + 1]; shorter.len() + 1
        ];
        /// 0 index for empty string case.
        for row in 1..dp.len() {
            for col in 1..dp[0].len() {
                let longer_char: char = longer.chars().nth(col - 1).unwrap();
                let shorter_char: char = shorter.chars().nth(row - 1).unwrap();
                if longer_char == shorter_char {
                    dp[row][col] = dp[row - 1][col - 1] + 1;
                } else {
                    dp[row][col] = std::cmp::max(
                        dp[row - 1][col - 1], 
                        std::cmp::max(dp[row][col - 1], dp[row - 1][col])
                    );
                }
            }
        }
        return dp[dp.len() - 1][dp[0].len() - 1];
    }
}
