class Solution {
public:
    inline void merge(
        std::vector<int32_t>& nums1, 
        int32_t m, 
        std::vector<int32_t>& nums2, 
        int32_t n
    ) {
        int32_t writter = m + n - 1;
        int32_t reader1 = m - 1;
        int32_t reader2 = n - 1;
        while (reader1 >= 0 && reader2 >= 0) {
            int32_t val1 = nums1[reader1];
            int32_t val2 = nums2[reader2];
            if (val1 >= val2) {
                nums1[writter] = val1;
                reader1 -= 1;
            } else {
                nums1[writter] = val2;
                reader2 -= 1;
            }
            writter -= 1;
        }
        while (reader2 >= 0) {
            nums1[writter] = nums2[reader2];
            writter -= 1;
            reader2 -= 1;
        }
        return;    
    }
};
