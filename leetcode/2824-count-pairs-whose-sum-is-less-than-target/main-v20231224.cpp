class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int32_t cnt = 0;
        for (int32_t i = 0; i < nums.size() - 1; ++i) {
            for (int32_t j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] >= target) { break; }
                cnt++;
            }
        }
        return cnt;
    }
};
