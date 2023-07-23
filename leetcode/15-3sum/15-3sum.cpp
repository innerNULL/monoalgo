

std::vector<std::vector<int32_t> > two_sum(
        vector<int>& sorted_nums, int64_t start_idx, int32_t target) {
    std::vector<std::vector<int32_t> > output;
    
    int64_t left_idx = start_idx;
    int64_t right_idx = sorted_nums.size() - 1;
    while (left_idx < right_idx) {
        int32_t left_val = sorted_nums[left_idx];
        int32_t right_val = sorted_nums[right_idx];
        int32_t curr_sum = left_val + right_val;
        if (curr_sum > target) {
            right_idx--;
        } else if (curr_sum < target) {
            left_idx++;
        } else {
            std::vector<int32_t> curr_output;
            curr_output.emplace_back(left_val);
            curr_output.emplace_back(right_val);
            output.emplace_back(curr_output);
            right_idx--;
            left_idx++;
        }
    }
    return output;
}


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int> > results;
        std::unordered_map<std::string, bool> recorder = {};
        
        std::sort(nums.begin(), nums.end());
        //for (auto x : nums) { printf("%i\n", x); }
        
        for (int32_t i = 0; i <= nums.size() - 3; ++i) {
            int32_t first_num = nums[i];
            int32_t sum_of_2nd_and_3rd = 0 - first_num;
            std::vector<std::vector<int32_t> > second_and_third_item = 
                two_sum(nums, i + 1, sum_of_2nd_and_3rd);
            if (i >= 1 && nums[i] == nums[i - 1]) { continue; }
            if (second_and_third_item.size() > 0) {
                /*
                for (auto x : second_and_third_item) {
                    for (auto y : x) { printf("%i ", y); }
                    printf("\n");
                }
                */
                for (auto x : second_and_third_item) {
                    int32_t second_num = x[0];
                    int32_t third_num = x[1];
                    std::string key = std::to_string(first_num) 
                        + "#" + std::to_string(second_num) 
                        + "#" + std::to_string(third_num); 
                    
                    if (recorder.find(key) != recorder.end()) { continue; } 
                    recorder[key] = true;
                        
                    std::vector<int> curr_result {
                        first_num, second_num, third_num
                    };
                    results.emplace_back(curr_result);
                }
            }
        }
        return results;
    }
};