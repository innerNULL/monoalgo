class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int32_t, int32_t> recorder = {};
        for (int32_t num : nums) {
            if (recorder.find(num) == recorder.end()) {
                recorder[num] = 0;
            }
            recorder[num]++;
        } 
        std::sort(
            nums.begin(), nums.end(), 
            [&recorder](int32_t a, int32_t b) { return recorder[a] > recorder[b]; }
        );
        std::unordered_map<int32_t, char> mem = {};
        std::vector<int32_t> results = {};
        for (int32_t num : nums) {
            if (mem.find(num) == mem.end()) {
                mem[num] = 0;
                results.emplace_back(num);
            }
            if (results.size() == k) { break; }
        }
        return results;
    }
};
