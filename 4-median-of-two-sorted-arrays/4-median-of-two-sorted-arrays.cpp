class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int32_t size_1 = nums1.size();
        int32_t size_2 = nums2.size();
        std::vector<int32_t> median_idx = {};
        std::vector<int32_t> median_val = {};
        int32_t reader_idx_1 = 0;
        int32_t reader_idx_2 = 0;
        if ((size_1 + size_2) % 2 == 0) {
            median_idx = {
                (size_1 + size_2) / 2 - 1, (size_1 + size_2) / 2
            };
        } else {
            median_idx = { (int32_t)((size_1 + size_2) / 2) };
        }
        //for (auto x : median_idx) { printf("%i\n", x); }
        //printf("above are median indexs\n");
        median_val = std::vector<int32_t>(median_idx.size(), 0);
        
        int32_t count = 0;
        int32_t target_median_idx = 0;
        while (reader_idx_1 < nums1.size() || reader_idx_2 < nums2.size()) {
            int32_t val_1 = 0;
            int32_t val_2 = 0;
            int32_t curr_cand = 0;
            
            if (reader_idx_1 < nums1.size() && reader_idx_2 < nums2.size()) {
                val_1 = nums1[reader_idx_1];
                val_2 = nums2[reader_idx_2];
                if (val_1 < val_2) {
                    curr_cand = val_1;
                    reader_idx_1++;
                } else {
                    curr_cand = val_2;
                    reader_idx_2++;
                }
            } else if (reader_idx_1 < nums1.size()) {
                val_1 = nums1[reader_idx_1];
                curr_cand = val_1;
                reader_idx_1++;
            } else {
                val_2 = nums2[reader_idx_2];
                curr_cand = val_2;
                reader_idx_2++;
            }
            count++;
            //printf("%i, %i, %i, %i\n", count, curr_cand, val_1, val_2);
            if (count - 1 == median_idx[target_median_idx]) {
                //printf("%i, %i\n", curr_cand, target_median_idx);
                median_val[target_median_idx] = curr_cand;
                target_median_idx++;
            }
            if (target_median_idx >= median_idx.size()) { break; }
            //printf("%i, %i, %i\n", count, reader_idx_1, reader_idx_2);
            //printf("end one loop\n");
        }
        int32_t median_sum = 0;
        for (auto x : median_val) { median_sum += x; }
        //printf("end\n");
        return (float)(median_sum) / median_val.size();
    }
};