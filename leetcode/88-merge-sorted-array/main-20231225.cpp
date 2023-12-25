class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int32_t read_idx1 = m - 1;
        int32_t read_idx2 = n - 1;
        int32_t write_idx = m + n - 1;
        while (read_idx1 >= 0 && read_idx2 >= 0) {
            const int32_t val1 = nums1[read_idx1];
            const int32_t val2 = nums2[read_idx2];
            if (val1 > val2) {
                nums1[write_idx] = val1;
                read_idx1--;
            } else {
                nums1[write_idx] = val2;
                read_idx2--;
            }
            write_idx--;
        }
        while (read_idx2 >= 0) {
            nums1[write_idx--] = nums2[read_idx2--];
        }
    }
};
