class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int32_t sum = 0;
        int32_t left_sum = 0;
        int32_t pivot_idx = -1;
        
        for (int x : nums) { sum += x; }
        for (int32_t i = 0; i < nums.size(); ++i) {
            int32_t right_sum = sum - left_sum - nums[i];
            if (left_sum == right_sum) { 
                pivot_idx = i;
                break;
            }
            left_sum += nums[i];
        }
        return pivot_idx;
    }
};