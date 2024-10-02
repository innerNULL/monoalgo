#include <vector>

using std::vector;


class Solution {
public:
    inline constexpr int32_t 
    removeDuplicates(vector<int32_t>& nums) {
        if (nums.size() <= 2) { 
            return static_cast<int32_t>(nums.size()); 
        }
        size_t write = 2;
        size_t read = 2;
        while (read < nums.size()) {
            if (nums[read] != nums[write - 2]) {
                nums[write] = nums[read];
                write += 1; 
            }
            read += 1;
        }
        return write;
    }
};
