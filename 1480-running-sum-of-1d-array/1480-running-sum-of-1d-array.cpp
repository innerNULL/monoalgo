class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int32_t i = 0; i < nums.size(); ++i) {
            if (i > 0) {
                nums[i] += nums[i-1];
            }
        }
        return nums;
    }
};