class Solution {
public:
    bool equalFrequency(string word) {
        std::unordered_map<char, size_t> char_freqs;
        for (size_t i = 0; i < word.size(); ++i) {
            const char c = word[i];
            if (char_freqs.find(c) == char_freqs.end()) { 
                char_freqs[c] = 1; 
            } else {
                char_freqs[c] += 1;
            }
        }
        for (char c : word) {
            char_freqs[c] -= 1;
            std::set<size_t> freqs;
            for (auto& [c, freq] : char_freqs) { 
                if (freq > 0) { freqs.insert(freq); }
            }
            if (freqs.size() == 1) { return true; }
            char_freqs[c] += 1;
        }
        return false;
    }
};
