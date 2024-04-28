class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char, int32_t> recorder = {};
        for (char c : magazine) {
            if (recorder.find(c) == recorder.end()) {
                recorder[c] = 0;
            }
            recorder[c] += 1;
        }
        for (char c : ransomNote) {
            if (recorder.find(c) == recorder.end()) {
                return false;
            }
            recorder[c] -= 1;
            if (recorder[c] < 0) {
                return false;
            }
        }
        return true;
    }
};
