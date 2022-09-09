class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.size() <= 1) { return; }

        int32_t left_idx = 0;
        int32_t right_idx = s.size() - 1;
        while (left_idx <= right_idx) {
            char tmp = s[left_idx];
            s[left_idx] = s[right_idx];
            s[right_idx] = tmp;
            left_idx++;
            right_idx--;
        } 
    }
};