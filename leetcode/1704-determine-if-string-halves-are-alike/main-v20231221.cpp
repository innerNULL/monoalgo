class Solution {
public:
    bool halvesAreAlike(string s) {
        const std::set<char> vowels = {
            'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'
        };
        int32_t len = static_cast<int32_t>(s.size()); 
        if (len == 0) { return true; }

        int32_t left_half_idx = len % 2 != 0 ? len / 2 : len / 2 - 1;
        int32_t right_half_idx = len % 2 != 0 ? len / 2 : len / 2;
        int32_t left_cnt = 0;
        int32_t right_cnt = 0;
        for (int32_t i = 0; i < len; ++i) {
            if (vowels.find(s[i]) == vowels.end()) { continue; }
            if (i <= left_half_idx) { left_cnt++; }
            if (i >= right_half_idx) { right_cnt++; }
        }
        return left_cnt == right_cnt;
    }
};
