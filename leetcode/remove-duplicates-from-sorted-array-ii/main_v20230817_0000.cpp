class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) { return nums.size(); }
        int32_t write_idx = 1;
        int32_t read_idx = 2;
        while (read_idx < nums.size()) {
            if (nums[read_idx] != nums[write_idx] 
                || nums[read_idx] != nums[write_idx - 1]
            ) {
                write_idx++;
                nums[write_idx] = nums[read_idx];
            }
            read_idx++;
        }
        return write_idx + 1;    
    }
};
