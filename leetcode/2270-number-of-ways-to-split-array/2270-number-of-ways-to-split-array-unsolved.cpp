class Solution {
public:
    int32_t waysToSplitArray(const std::vector<int32_t>& nums) {
        const int32_t size = static_cast<int32_t>(nums.size());
        if (size <= 1) { return 0; }

        std::vector<intmax_t> left_sum;
        std::vector<intmax_t> right_sum;
        left_sum.resize(size - 1);
        right_sum.resize(size - 1);
        
        intmax_t sum = std::accumulate(nums.begin(), nums.end(), 0);
        //printf("sum=%i\n", sum);
        int32_t split_points_cnt = 0;
        for (int32_t i = 0; i < size - 1; ++i) {
            left_sum[i] = i == 0 ? nums[i] : nums[i] + left_sum[i - 1];
            right_sum[i] = sum - left_sum[i];
            //printf("left=%i\n", left_sum[i]);
            //printf("right-%i\n", right_sum[i]);
            if (left_sum[i] >= right_sum[i]) { split_points_cnt++; }
        }
        return split_points_cnt;
    }
};
