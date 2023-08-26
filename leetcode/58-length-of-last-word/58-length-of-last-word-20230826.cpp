class Solution {
public:
    int lengthOfLastWord(string s) {
        int32_t end_idx = s.size() - 1;
        while (end_idx >= 0 && s[end_idx] == ' ') { end_idx--; }
        if (end_idx == -1) { return 0; }
        int32_t start_idx = end_idx;
        while (start_idx >= 0 && s[start_idx] != ' ') { start_idx--; }
        //printf("start_idx=%i, end_idx=%i\n", start_idx, end_idx);
        return end_idx - start_idx;    
    }
};
