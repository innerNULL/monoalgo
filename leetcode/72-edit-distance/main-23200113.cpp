constexpr void print_2darray(
    const std::vector<std::vector<int32_t>>& array
) {
    for (int32_t i = 0; i < array.size(); ++i) {
        for (int32_t j = 0; j < array[0].size(); ++j) {
            printf("%i ", array[i][j]);
        }
        printf("\n");
    }
}


class Solution {
public:
    int minDistance(string word1, string word2) {
        int32_t size1 = word1.size();
        int32_t size2 = word2.size();

        if (size1 == 0 || size2 == 0) { return std::max(size1, size2); }

        // dp[i][j]: Edit distance between word1[0:i + 1] and word2[0:j + 1]
        std::vector<std::vector<int32_t>> dp(
            size1 + 1, std::vector<int32_t>(size2 + 1, 0)
        );
        for (int32_t i = 1; i <= size1; ++i) { dp[i][0] = i; }
        for (int32_t j = 1; j <= size2; ++j) { dp[0][j] = j; }
        for (int32_t i = 1; i <= size1; ++i) {
            for (int32_t j = 1; j <= size2; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::min(
                        dp[i - 1][j - 1], 
                        std::min(dp[i - 1][j], dp[i][j - 1])
                    ) + 1;
                }
            }
        }
        //print_2darray(dp);
        return dp[size1][size2];
    }
};

