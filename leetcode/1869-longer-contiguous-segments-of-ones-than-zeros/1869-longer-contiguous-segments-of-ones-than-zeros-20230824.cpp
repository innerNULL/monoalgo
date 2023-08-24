

int32_t longest_contiguous_char(const std::string& seq, const char& target) {
    int32_t max_len = 1;
    int32_t start_idx = 0;
    int32_t end_idx = 0;
    while (start_idx < seq.size()) {
        while (start_idx < seq.size()) {
            if (seq[start_idx] != target) {
                start_idx++;
            } else {
                break;
            }
        }
        end_idx = start_idx;
        while (end_idx < seq.size()) { 
            if (seq[end_idx] == target) { 
                end_idx++; 
            } else {
                break;
            }
        }
        max_len = std::max(end_idx - start_idx, max_len);
        start_idx = end_idx;

    }
    return max_len;
}


class Solution {
public:
    bool checkZeroOnes(string s) {
        if (s.size() == 0) { return false; }
        if (s.size() == 1) {
            return s[0] == '1' ? true : false;
        }
        return longest_contiguous_char(s, '1') > longest_contiguous_char(s, '0');
    }
};
