class Solution {
public:
    std::vector<int32_t> 
    getAverages(const std::vector<int32_t>& nums, int32_t k) {
        if (k < 1) { return nums; }
        size_t size = nums.size();
        int32_t subarray_len = k * 2 + 1;
        std::vector<int64_t> sums(size, -1);
        std::vector<int32_t> out(size, -1);
        if (size < subarray_len) { return out; }
        int32_t left_idx = 0;
        int32_t mid_idx = 0 + k;
        int32_t right_idx = left_idx + subarray_len - 1;
        int64_t sum = 0;
        for (int32_t i = left_idx; i <= right_idx; ++i) {
            sum += nums[i];
        }
        while (right_idx < size) {
            //printf("%i, %i, %i\n", left_idx, mid_idx, right_idx);
            //printf("sum=%i\n", sum);
            sums[mid_idx] = sum;
            if (right_idx < size - 1) {
                sum = sum - nums[left_idx] + nums[right_idx + 1];
            }
            left_idx += 1;
            mid_idx += 1;
            right_idx += 1;
        }
        for (int32_t i = 0; i < size; ++i) { 
            if (sums[i] == -1) { 
                out[i] = -1;
            } else {
                out[i] = (int32_t)(sums[i] / (int64_t)subarray_len);
            }
        }
        //printf("end\n");
        return out;
    }
};
