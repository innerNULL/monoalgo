class Solution {
public:
    constexpr inline int32_t 
    removeDuplicates(std::vector<int32_t>& nums) { 
        int32_t writter = 1;
        for (int32_t i = 1; i < nums.size(); ++i) {
            const int32_t curr_val = nums[i];
            const int32_t last_val = nums[i - 1];
            if (curr_val != last_val) {
                nums[writter] = curr_val;
                writter += 1;
            }
        }
        return writter;   
    }
};
