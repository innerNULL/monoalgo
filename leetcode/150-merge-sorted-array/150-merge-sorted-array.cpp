class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int32_t reader1 = m - 1;
        int32_t reader2 = n - 1; 
        int32_t writer = m + n - 1;
        while (reader1 >= 0 && reader2 >= 0) {
            int32_t val1 = nums1[reader1];
            int32_t val2 = nums2[reader2];
            if (val1 >= val2) {
                nums1[writer] = val1;
                reader1--;
            } else {
                nums1[writer] = val2;
                reader2--;
            }
            writer--;
        }
        while (reader2 >= 0) {
            nums1[writer] = nums2[reader2];
            reader2--;
            writer--;
        }
    }
};
