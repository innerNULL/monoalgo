class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int32_t nums_len = static_cast<int32_t>(nums.size());
        if (nums_len <= 1) {
            return nums_len;
        }
        int32_t write_idx = 0;
        int32_t read_idx = write_idx;
        while (read_idx < nums_len) {
            //printf("%i, %i\n", write_idx, read_idx);
            int32_t last_val = nums[write_idx];
            while (read_idx < nums_len && nums[read_idx] == last_val) {
                read_idx++;
            }
            if (read_idx == nums_len) { break; }
            write_idx += 1;
            if (write_idx == nums_len) { break; }
            nums[write_idx] = nums[read_idx];
            read_idx += 1;
        } 
        return write_idx + 1;
    }
};
