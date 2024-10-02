class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return nums[static_cast<int32_t>(nums.size()) / 2];   
    }
};
