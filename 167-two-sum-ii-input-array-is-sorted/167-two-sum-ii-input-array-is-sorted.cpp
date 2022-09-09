class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::vector<int32_t> out;
        if (numbers.size() <= 1) { return out; }

        int32_t left_idx = 0;
        int32_t right_idx = numbers.size() - 1;
        while (left_idx < right_idx) {
            int32_t left_val = numbers[left_idx];
            int32_t right_val = numbers[right_idx];
            int32_t curr_sum = left_val + right_val;
            if (curr_sum > target) {
                right_idx -= 1;
            } else if (curr_sum < target) {
                left_idx += 1;
            } else {
                out.emplace_back(left_idx + 1);
                out.emplace_back(right_idx + 1);
                break;
            }
        }
        return out;
    }
};