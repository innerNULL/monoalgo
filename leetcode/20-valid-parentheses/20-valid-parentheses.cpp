class Solution {
public:
    bool isValid(string s) {
        int32_t s_size = s.size();
        if (s_size == 0) { return true; }
        if (s_size % 2 != 0) { return false; }

        std::stack<char> recorder;

        std::set<char> left = {'(', '[', '{'};
        std::unordered_map<char, char> right2left; 
        right2left[')'] = '(';
        right2left[']'] = '[';
        right2left['}'] = '{';

        for (char c : s) {
            if (left.find(c) != left.end()) {
                recorder.push(c);
            } else {
                if (recorder.size() == 0) {
                    return false;
                } else if (right2left[c] != recorder.top()) {
                    return false;
                } else {
                    recorder.pop();
                }
            }
        }
        return (recorder.size() == 0);
    }
};