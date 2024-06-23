#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")


#include <set>
#include <string>
#include <vector>


const std::set<char> VOWELS = {
    'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'
};


class Solution {
public:
    inline std::string sortVowels(std::string& s) {
        std::vector<char> vowels;
        for (const char& c : s) {
            if (VOWELS.find(c) != VOWELS.end()) {
                vowels.emplace_back(c);
            }
        }
        std::sort(vowels.begin(), vowels.end());
        size_t idx = 0;
        for (char& c : s) {
            if (VOWELS.find(c) != VOWELS.end()) {
                c = vowels[idx];
                idx += 1;
            }
        }
        return s;
    }
};
