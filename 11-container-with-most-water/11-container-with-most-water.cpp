

class Solution {
public:
    int maxArea(vector<int>& height) {
        int64_t left_idx = 0;
        int64_t right_idx = height.size() - 1;
        
        int32_t max_area= 0;
        
        while (left_idx < right_idx) {
            int32_t& left_val = height[left_idx];
            int32_t& right_val = height[right_idx];
            int32_t curr_area = std::min(left_val, right_val) * (right_idx - left_idx);
            //printf("dbg: left_idx=%ld, right_idx=%ld\n", left_idx, right_idx);
            //printf("dbg: left_val=%ld, right_val=%ld\n", left_val, right_val);
            //printf("%i, %ld\n", std::min(left_val, right_val), right_idx - left_idx);
            //printf("dbg: curr_area=%i\n", curr_area);
            if (curr_area > max_area) { max_area = curr_area; }
            if (left_val <= right_val) {
                left_idx++;
            } else {
                right_idx--;
            }
        }
    
        return max_area;
    }
};