class Solution {
public:
    static void reverse(
            std::vector<int32_t>& nums, 
            int32_t start_idx, int32_t end_idx) {
        while (start_idx <= end_idx) {
            int32_t tmp = nums[start_idx];
            nums[start_idx] = nums[end_idx];
            nums[end_idx] = tmp;
            start_idx++;
            end_idx--;
        }
    }
        
    void rotate(vector<int>& nums, int k) {
        if (k == 0) { return; }
        if (nums.size() < k) { k = k % nums.size(); }
        
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};