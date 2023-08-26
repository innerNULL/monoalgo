

void backtrack(
    std::vector<std::vector<int32_t>>* dest, 
    std::vector<int32_t>& tmp_result, const std::vector<int32_t>& nums
) {
    if (tmp_result.size() == nums.size()) {
        dest->emplace_back(tmp_result);
    } else {
        for (const int32_t& num : nums) {
            if (std::find(
                    tmp_result.begin(), tmp_result.end(), num
                ) == tmp_result.end()
            ) {
                tmp_result.emplace_back(num);
                backtrack(dest, tmp_result, nums);
                tmp_result.pop_back();
            }
        }
    }
}


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int32_t>> dest = {};
        std::vector<int32_t> tmp_result = {};
        backtrack(&dest, tmp_result, nums);
        return dest;
    }
};
