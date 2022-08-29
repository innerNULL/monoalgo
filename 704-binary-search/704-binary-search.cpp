class Solution {
public:
    int search(vector<int>& nums, int target) {
        int32_t target_idx = -1;
        
        int32_t start_idx = 0;
        int32_t end_idx = nums.size() - 1;
        int32_t mid_idx = -1;
        
        while (true) {
            int32_t mid_idx = (start_idx + end_idx) / 2;
            int32_t mid_val = nums[mid_idx];
            //printf("dbg: %i, %i, %i\n", start_idx, end_idx, mid_idx);
            if (mid_val == target) {
                return mid_idx;
            } else if (mid_val < target) {
                start_idx = mid_idx;
            } else {
                end_idx = mid_idx;
            }
            if (start_idx == end_idx) { break; }
            /// Marginal case
            if (start_idx == end_idx - 1) {
                if (nums[start_idx] < target) { 
                    start_idx = end_idx; 
                } 
            }
        }
        return mid_idx;
    }
};