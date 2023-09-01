class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<int32_t> dp = {0};
        dp.resize(n);
        dp[0] = 1;
        int32_t multi2_idx = 0;
        int32_t multi3_idx = 0;
        int32_t multi5_idx = 0;
        for (int32_t i = 1; i < n; ++i) {
            int32_t multi2_val = dp[multi2_idx] * 2;
            int32_t multi3_val = dp[multi3_idx] * 3;
            int32_t multi5_val = dp[multi5_idx] * 5;
            //printf("%i, %i, %i\n", multi2_val, multi3_val, multi5_val);
            if (multi2_val <= multi3_val && multi2_val <= multi5_val) {
                dp[i] = multi2_val;
                multi2_idx++;
            } 
            if (multi3_val <= multi2_val && multi3_val <= multi5_val) {
                dp[i] = multi3_val;
                multi3_idx++;
            } 
            if (multi5_val <= multi2_val && multi5_val <= multi3_val) {
                dp[i] = multi5_val;
                multi5_idx++;
            }
        }
        return dp[n - 1];
    }
};
