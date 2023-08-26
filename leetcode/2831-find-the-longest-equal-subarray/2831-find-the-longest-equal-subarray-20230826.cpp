class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        std::unordered_map<int32_t, int32_t> recorder = {};
        int32_t max_freq = 0;
        int32_t start_idx = 0;
        int32_t end_idx = 0;
        while (end_idx < nums.size()) {
            int32_t window_size = end_idx - start_idx + 1;
            int32_t curr_num = nums[end_idx];
            if (recorder.find(curr_num) == recorder.end()) {
                recorder[curr_num] = 0;
            }
            recorder[curr_num]++;
            max_freq = std::max(recorder[curr_num], max_freq);
            if (window_size - max_freq > k) {
                recorder[nums[start_idx]]--;
                start_idx++;
            }
            end_idx++;
        }
        return max_freq; 
    }
};
