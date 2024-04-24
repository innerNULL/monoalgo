class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int32_t nums_len = static_cast<int32_t>(nums.size());
        if (nums_len <= 2) { return nums_len; }

        int32_t write_idx = 1;
        int32_t read_idx = 2;
        while (true) {
            if (read_idx >= nums_len) { break; }
            while (read_idx < nums_len && nums[read_idx] == nums[write_idx - 1]) {
                read_idx++;
            }
            if (read_idx == nums_len) { break; }
            nums[++write_idx] = nums[read_idx++];
        }
        return write_idx + 1;
    }
};
