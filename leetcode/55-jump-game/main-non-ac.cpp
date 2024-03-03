class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) { return true; }
        if (nums[0] == 0) { return false; }
        if (nums.size() == 2) { return nums[0] >= 1; }

        int32_t len = static_cast<int32_t>(nums.size());
        int32_t idx = 0;
        bool condition = false;
        if (nums[0] == 0) {
            return false;
        } else {
            for (int32_t i = 1; i <= nums[0]; ++i) {
                if (i >= nums.size()) { break; }
                std::vector<int32_t> next_vec = std::vector<int32_t>(
                    &nums[i], &nums[nums.size()]
                );
                condition = condition || canJump(next_vec);
            }
            return condition;
        }
    }
};
