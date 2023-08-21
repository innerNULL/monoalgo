class Solution {
public:
    int findLucky(vector<int>& arr) {
        std::unordered_map<int32_t, int32_t> recorder = {};
        for (const int32_t& x : arr) {
            if (recorder.find(x) == recorder.end()) {
                recorder[x] = 0;
            }
            recorder[x]++;
        } 
        int32_t max_lucky_num = -1;
        for (const auto& pair : recorder) {
            if (pair.first == pair.second && pair.first > max_lucky_num) {
                max_lucky_num = pair.first;
            }
        }
        return max_lucky_num;
    }
};
