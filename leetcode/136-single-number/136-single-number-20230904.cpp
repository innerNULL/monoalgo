class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::unordered_map<int32_t, int32_t> mem = {};
        for (int32_t num : nums) {
            if (mem.find(num) == mem.end()) { mem[num] = 0; }
            mem[num]++;
        }
        for (int32_t num : nums) {
            if (mem[num] == 1) { return num; }
        }
        return 0;
    }
};
