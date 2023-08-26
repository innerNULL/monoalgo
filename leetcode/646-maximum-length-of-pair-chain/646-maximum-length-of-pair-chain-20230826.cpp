class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.size() <= 1) { return pairs.size(); }
        std::sort(
            pairs.begin(), pairs.end(), 
            [](const std::vector<int32_t>& a, const std::vector<int32_t>& b) {
                return a[1] < b[1];
            }
        );
        int32_t cnt = 1;
        int32_t last_2nd = pairs[0][1];
        for (int32_t i = 1; i < pairs.size(); ++i) {
            const std::vector<int32_t>& curr_pair = pairs[i];
            if (curr_pair[0] > last_2nd) {
                last_2nd = curr_pair[1];
                cnt++;
            }
        }
        return cnt;
    }
};
