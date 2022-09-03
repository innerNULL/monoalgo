

int32_t get_closest_two_sum(
        vector<int>& nums, int64_t start_idx, int32_t target) {
    int32_t closest_sum = 0;
    int32_t smallest_abs_diff = 0;
    
    int64_t left_idx = start_idx;
    int64_t right_idx = nums.size() - 1;
    
    while (left_idx < right_idx) {
        int32_t curr_sum = nums[left_idx] + nums[right_idx];
        int32_t curr_abs_diff = std::abs(target - curr_sum);
        
        if (left_idx == start_idx) {
            closest_sum = curr_sum;
            smallest_abs_diff = curr_abs_diff;
        } else if (curr_abs_diff < smallest_abs_diff) {
            closest_sum = curr_sum;
            smallest_abs_diff = curr_abs_diff;
        }
        if (curr_sum < target) {
            left_idx++;
        } else if (curr_sum > target) {
            right_idx--;
        } else {
            break;
        }
    }
    return closest_sum;
}


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int32_t closest_sum = 0;
        int32_t smallest_abs_diff = 0;
        
        std::sort(nums.begin(), nums.end());
        //for (auto x : nums) { printf("%i\n", x); }
        
        for (int32_t i = 0; i < nums.size() - 2; ++i) {
            int32_t first_num = nums[i];
            int32_t target_two_sum = target - first_num;
            int32_t closest_two_sum = get_closest_two_sum(
                nums, i + 1, target_two_sum);
            int32_t curr_abs_diff = std::abs(target_two_sum - closest_two_sum);
            //printf("dbg: first_num=%i\n", first_num);
            //printf("dbg: target_two_sum=%i\n", target_two_sum);
            //printf("dbg: closest_two_sum=%i\n", closest_two_sum);
            //printf("dbg: curr_abs_diff=%i\n", curr_abs_diff);
            if (i == 0 || curr_abs_diff < smallest_abs_diff) {
                closest_sum = first_num + closest_two_sum;
                smallest_abs_diff = curr_abs_diff;
            } 
            if (smallest_abs_diff == 0) { break; }
        }
        return closest_sum;
    }
};