// The API isBadVersion is defined for you.
// bool isBadVersion(int version);


class Solution {
public:
    int firstBadVersion(int n) {
        int64_t first_bad_idx = -1;
        
        int64_t start_idx = 0;
        int64_t end_idx = n - 1;
        int64_t mid_idx = -1;
        while (start_idx < end_idx) {
            mid_idx = (start_idx + end_idx) / 2;
            int64_t mid_version = mid_idx + 1;
            if (isBadVersion(mid_version)) {
                first_bad_idx = mid_version;
                end_idx = mid_idx;
            } else {
                start_idx = mid_idx + 1;
            }
        }
        if (start_idx == end_idx && isBadVersion(start_idx + 1)) {
            first_bad_idx = start_idx;
        }
        return first_bad_idx + 1;
    }
    
    
    int firstBadVersion_v0(int n) {
        int64_t first_one_idx = -1;
        
        int64_t start_idx = 0;
        int64_t end_idx = n - 1;
        int64_t mid_idx = -1;
        
        int64_t mid_val = -1;
        while (true) {
            //printf("info: start_idx=%i, end_idx=%i\n", start_idx, end_idx);
            mid_idx = (start_idx + end_idx) / 2;
            mid_val = mid_idx + 1;
            //printf("info: mid_idx=%i, mid_val=%i\n", mid_idx, mid_val);
            if (isBadVersion(mid_val)) {
                first_one_idx = mid_idx;
                end_idx = mid_idx;
            } else {
                start_idx = mid_idx;
            }
            //printf("info: start_idx=%i, end_idx=%i\n", start_idx, end_idx);
            if (start_idx == end_idx) { break; }
            if (start_idx == end_idx - 1) {
                int32_t end_val = end_idx + 1;
                if (isBadVersion(end_val)) {
                    first_one_idx = end_idx;
                    end_idx -= 1;
                }
            }            
        }
        int64_t first_one_val = first_one_idx + 1;
        return first_one_val;
    }
};