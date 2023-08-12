class Solution {
public:
    int specialArray(std::vector<int>& nums) {
        if (nums.size() == 0) { return -1; }
        std::sort(nums.begin(), nums.end(), std::greater<int32_t>());
        if (nums.size() <= nums[nums.size() - 1]) { return nums.size(); }
        for (int32_t i = 0; i < nums.size() - 1; ++i) {
            int32_t cand_x = i + 1;
            printf("dbg: cand_x=%i, val=%i\n", cand_x, nums[i]);
            if (cand_x <= nums[i] && cand_x > nums[i + 1]) { return cand_x; }
        }
        return -1;
    }
};
