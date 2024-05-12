#include <set>


const std::set<char> VOWELS = {
    'a', 'e', 'i', 'o', 'u',
    'A', 'E', 'I', 'O', 'U'
};


class Solution {
public:
    int maxVowels(string s, int k) {
        size_t left = 0;
        size_t right = k - 1;
        int32_t curr_vowels_cnt = 0;
        int32_t max_vowels_cnt = 0; 

        for (size_t i = 0; i < k; ++i) {
            if (VOWELS.find(s[i]) != VOWELS.end()) {
                curr_vowels_cnt += 1;
            }
        }
        max_vowels_cnt = curr_vowels_cnt;
        while (right < s.size() - 1) {
            if (VOWELS.find(s[left]) != VOWELS.end()) {
                curr_vowels_cnt -= 1;
            }
            if (VOWELS.find(s[right + 1]) != VOWELS.end()) {
                curr_vowels_cnt += 1;
            }
            left += 1;
            right += 1;
            max_vowels_cnt = std::max(
                max_vowels_cnt, curr_vowels_cnt
            );
        }
        return max_vowels_cnt;
    }
};
