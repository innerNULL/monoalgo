class Solution {
public:
    inline bool checkString(const std::string& s) {
        int32_t min_b_idx = -1;
        for (int32_t i = 0; i < s.size(); ++i) {
            if (s[i] == 'b') {
                min_b_idx = i;
                break;
            }
        }
        for (int32_t i = min_b_idx; i < s.size(); ++i) {
            if (s[i] == 'a') { return false; }
        }
        return true;
    }
};
