class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int32_t write_idx = 0;
        int32_t read_idx = 1;
        while (read_idx < nums.size()) {
            if (nums[read_idx] != nums[write_idx]) {
                write_idx++;
                nums[write_idx] = nums[read_idx];
            }
            read_idx++;
        }  
        return write_idx + 1;
    }
};
