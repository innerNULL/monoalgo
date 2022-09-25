class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int32_t, int32_t> recorder = {};
        std::vector<int32_t> result;
        for (int32_t i = 0; i < nums.size(); ++i) {
            const int32_t curr = nums[i];
            const int32_t left = target - curr;
            if (recorder.find(left) != recorder.end()) {
                result.emplace_back(i);
                result.emplace_back(recorder[left]);
                return result;
            }
            recorder[curr] = i;
        }
        return result;
    }

    vector<int> twoSum_v0(vector<int>& nums, int target) {
        int current_sum;
        vector<int> output;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            int a = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                int b = nums[j];
                
                if ((a + b) == target) {
                    output.emplace_back(i);
                    output.emplace_back(j);
                    //printf("The result is: %i, %i\n", i, j);
                    return output;
                }
            }
        }
        output.emplace_back(-1);
        output.emplace_back(-1);
        return output;
    }
};