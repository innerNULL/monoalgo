class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int64_t left_idx = 0;
        int64_t right_idx = 1;
        while (right_idx < nums.size()) {
            int32_t right_val = nums[right_idx];
            int32_t left_val = nums[left_idx];
            if (left_val == right_val) {
                right_idx++;
            } else {
                left_idx++;
                right_idx++;
                nums[left_idx] = right_val;
            }
        }  
        return left_idx + 1;
    }
};
