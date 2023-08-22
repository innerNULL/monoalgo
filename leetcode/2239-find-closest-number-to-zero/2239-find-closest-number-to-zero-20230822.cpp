class Solution {
public:
    inline int findClosestNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int32_t result = 0;
        int32_t min_dist = INT_MAX;
        for (const auto& num : nums) {
            int32_t curr_dist = std::abs(num);
            if (curr_dist <= min_dist) { 
                min_dist = std::move(curr_dist);
                result = num; 
            }
        }    
        return result;
    }
};
