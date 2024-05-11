#include <set>


const std::set<char> VOWELS = {
    'a', 'e', 'i', 'o', 'u',
    'A', 'E', 'I', 'O', 'U'
};


class Solution {
public:
    string reverseVowels(string s) {
        if (s.size() <= 1) {
            return std::move(s);
        }
        std::vector<size_t> vowels_idxs = {};
        for (size_t i = 0; i < s.size(); ++i) {
            if (VOWELS.find(s[i]) != VOWELS.end()) {
                vowels_idxs.emplace_back(i);
            }
        }
        if (vowels_idxs.size() == 0) {
            return std::move(s);
        }
        size_t left = 0;
        size_t right = vowels_idxs.size() - 1;
        while (left < right) {
            char tmp = s[vowels_idxs[left]];
            s[vowels_idxs[left]] = s[vowels_idxs[right]];
            s[vowels_idxs[right]] = tmp;
            left += 1;
            right -= 1;
        }
        return std::move(s);
    }
};
