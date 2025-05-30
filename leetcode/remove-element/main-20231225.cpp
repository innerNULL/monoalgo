class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        const int32_t nums_len = static_cast<int32_t>(nums.size());
        if (nums_len == 0) { 
            return 0; 
        } else if (nums_len == 1) {
            return nums[0] == val ? 0 : 1;
        }
        int32_t left_idx = 0;
        int32_t right_idx = nums_len - 1;
        while (left_idx < right_idx) {
            while (left_idx < nums_len - 1 && nums[left_idx] != val) { 
                left_idx++; 
            }
            while (right_idx > 0 && nums[right_idx] == val) { 
                right_idx--; 
            }   
            //printf("%i, %i\n", left_idx, right_idx);
            if (left_idx >= right_idx) {
                break;
            } 
            if (nums[left_idx] == val && nums[right_idx] != val) {
                nums[left_idx++] = nums[right_idx];
                nums[right_idx--] = val;
            }
        } 
        int32_t k = 0;
        while (k < nums_len && nums[k] != val) { k++; }
        return k;
    }
};
