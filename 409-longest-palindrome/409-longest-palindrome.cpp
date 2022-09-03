class Solution {
public:
    int longestPalindrome(string s) {
        int32_t potential_len = 0;
        
        std::unordered_map<char, int32_t> recorder = {};
        for (int32_t i = 0; i < s.size(); ++i) {
            char curr_char = s.at(i);
            if (recorder.find(curr_char) == recorder.end()) {
                recorder[curr_char] = 1;
            } else {
                recorder[curr_char] += 1;
            }
        }
        
        int32_t odd_count = 0;
        std::unordered_map<char, int32_t>::iterator iter = recorder.begin();
        while (iter != recorder.end()) {
            int32_t curr_char_count = iter->second;
            if (curr_char_count == 1 && odd_count < 1) {
                potential_len += 1;
                odd_count += 1;
            } else {
                potential_len = potential_len + curr_char_count / 2 * 2;
                if (odd_count < 1 && curr_char_count % 2 == 1) {
                    potential_len += 1;
                    odd_count += 1;
                }
            }
            iter++;
        }
        return potential_len;
    }
};