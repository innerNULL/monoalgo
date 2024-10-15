#include <vector>
#include <algorithm>   

using std::vector;


class Solution {
public:
    inline constexpr int32_t 
    minSubArrayLen(int32_t target, const vector<int32_t>& nums) {
        size_t left = 0;
        size_t right = 0;
        int32_t sum = 0;
        int32_t min_len = INT_MAX;
        while (right < nums.size()) {
            sum += nums[right];
            while (sum >= target) {
                sum -= nums[left];
                min_len = std::min(
                    min_len, 
                    static_cast<int32_t>(right - left + 1)
                );
                left += 1;
            }
            right += 1;
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};
