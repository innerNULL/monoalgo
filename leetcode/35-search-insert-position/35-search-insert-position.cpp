class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int64_t start_idx = 0;
        int64_t end_idx = nums.size() - 1;
        int64_t mid_idx = -1;
        int64_t target_idx = -1;
        
        while (start_idx < end_idx - 1) {
            mid_idx = (start_idx + end_idx) / 2;
            //printf("start_idx=%i, end_idx=%i\n", start_idx, end_idx);
            //printf("mid_idx=%i, target_idx=%i\n", mid_idx, target_idx);
            
            int64_t start_val = nums[start_idx];
            int64_t end_val = nums[end_idx];
            int64_t mid_val = nums[mid_idx];
            
            if (mid_val < target) {
                start_idx = mid_idx;
                target_idx = mid_idx;
            } else {
                end_idx = mid_idx;
            }
            //printf("start_idx=%i, end_idx=%i\n", start_idx, end_idx);
        }
        //if (nums[target_idx + 1] < target) { target_idx += 1; }
        //if (nums[target_idx + 1] > target) { target_idx -= 1; }
        if (nums[start_idx] >= target) { return 0; }
        if (nums[end_idx] < target) { return end_idx + 1; }
        return start_idx + 1;
    }
};