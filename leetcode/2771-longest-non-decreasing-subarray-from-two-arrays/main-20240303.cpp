class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int32_t max_end_with_1 = 1;
        int32_t max_end_with_2 = 1;
        int32_t result = 1;
        
        for (int32_t i = 1; i < nums1.size(); ++i) {
            int32_t num1to1 = 
                nums1[i] < nums1[i - 1] ? 1 : max_end_with_1 + 1;
            int32_t num1to2 = 
                nums2[i] < nums1[i - 1] ? 1 : max_end_with_1 + 1;
            int32_t num2to1 = 
                nums1[i] < nums2[i - 1] ? 1 : max_end_with_2 + 1;
            int32_t num2to2 = 
                nums2[i] < nums2[i - 1] ? 1 : max_end_with_2 + 1;
            
            max_end_with_1 = std::max(num1to1, num2to1);
            max_end_with_2 = std::max(num1to2, num2to2);

            result = std::max(
                result, 
                std::max(max_end_with_1, max_end_with_2)
            );
        }
        return result; 
    }
};
