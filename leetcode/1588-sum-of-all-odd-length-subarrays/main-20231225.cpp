class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        const int32_t arr_len = static_cast<int32_t>(arr.size());
        int32_t ans = 0;
        for (int32_t left = 0; left < arr_len; ++left) {
            int32_t curr_sum = 0;
            for (int32_t right = left; right < arr_len; ++right) {
                curr_sum += arr[right];
                if ((right - left) % 2 == 0) {
                    ans += curr_sum;
                }
            }
        }   
        return ans;
    }
};
