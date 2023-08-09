class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) { 
            return -1; 
        } else if (nums.size() == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int32_t left_idx = 0;
        int32_t right_idx = nums.size() - 1;
        int32_t left_val = nums[left_idx];
        int32_t right_val = nums[right_idx];    
        while (left_idx <= right_idx) {
            if (left_idx == right_idx && left_val != target) {
                break;
            }
            const int32_t mid_idx = (left_idx + right_idx) / 2;
            const int32_t mid_val = nums[mid_idx];
            //printf("%i, %i, %i\n", left_idx, right_idx, mid_idx);
            if (mid_val == target) { return mid_idx; }
            if (mid_val >= left_val) {
                if (target < mid_val && target >= left_val) {
                    //printf("c0\n");
                    right_idx = mid_idx - 1;
                } else {
                    //printf("c1\n");
                    left_idx = mid_idx + 1;
                }
            } else {
                if (target <= right_val && target > mid_val) {
                    //printf("c2\n");
                    left_idx = mid_idx + 1;
                } else {
                    //printf("c3\n");
                    right_idx = mid_idx - 1;
                }
            }
            left_val = nums[left_idx];
            right_val = nums[right_idx];
        }
        return -1;
    }
};
