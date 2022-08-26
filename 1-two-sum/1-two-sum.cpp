class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int current_sum;
        vector<int> output;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            int a = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                int b = nums[j];
                
                if ((a + b) == target) {
                    output.push_back(i);
                    output.push_back(j);
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