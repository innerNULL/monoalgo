class Solution {
public:
    inline int32_t 
    removeElement(
        std::vector<int32_t>& nums, 
        const int32_t val
    ) {
        int32_t writter = 0;
        for (int32_t i = 0; i < nums.size(); ++i) {
            const int32_t curr_val = nums[i];
            if (curr_val != val) {
                nums[writter++] = curr_val;
            }
        }
        return writter;
    }
};
