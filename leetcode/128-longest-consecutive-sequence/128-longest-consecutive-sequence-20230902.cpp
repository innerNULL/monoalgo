class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1) { return nums.size(); }
        std::sort(nums.begin(), nums.end());
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
        int32_t left_idx = 0;
        int32_t right_idx = 0;
        int32_t max_len = 1;
        while (left_idx < nums.size() && right_idx < nums.size()) {
            right_idx  = left_idx + 1;
            if (right_idx == nums.size()) { break; }
            //printf("left_idx=%i, right_idx=%i\n", left_idx, right_idx);
            while (
                right_idx < nums.size()
                && nums[right_idx] == nums[right_idx - 1] + 1 
            ) {
                right_idx++;
            }
            max_len = std::max(max_len, right_idx - left_idx);
            if (right_idx == nums.size()) { break; }
            left_idx = right_idx;
        }
        return max_len; 
    }
};
