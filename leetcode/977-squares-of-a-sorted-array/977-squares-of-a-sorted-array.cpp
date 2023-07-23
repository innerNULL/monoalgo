class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        std::vector<int> output;
        std::stack<int> recorder;
        
        if (nums.size() == 0) { return output; }
        if (nums.size() == 1) {
            output.emplace_back(nums[0] * nums[0]);
            return output;
        }
        
        int32_t left_idx = 0;
        int32_t right_idx = nums.size() - 1;
        while (left_idx <= right_idx) {
            int32_t left_val = nums[left_idx];
            int32_t right_val = nums[right_idx];
            int32_t left_val_pow = left_val * left_val;
            int32_t right_val_pow = right_val * right_val;
            if (left_val_pow > right_val_pow) {
                recorder.push(left_val_pow);
                left_idx++;
            } else if (right_val_pow > left_val_pow) {
                recorder.push(right_val_pow);
                right_idx--;
            } else {
                recorder.push(left_val_pow);
                if (left_idx != right_idx) { 
                    recorder.push(right_val_pow); 
                }
                left_idx++;
                right_idx--;
            }
        }
        while (recorder.size() > 0) { 
            output.emplace_back(recorder.top());
            recorder.pop();
        }
        return output;
    }
};