class Solution {
public:
    constexpr inline int32_t 
    removeDuplicates(std::vector<int32_t>& nums) {
        if (nums.size() <= 2) {
            return static_cast<int32_t>(nums.size());
        }
        int32_t writter = 2;
        for (int32_t i = 2; i < nums.size(); ++i) {
            const int32_t curr_val = nums[i];
            if (curr_val != nums[writter - 2]) {
                nums[writter] = curr_val;
                writter += 1;
            }
        }
        return writter;
    }
};
