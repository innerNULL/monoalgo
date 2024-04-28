class Solution {
public:
    bool isValid(const std::string& s) {
        std::stack<char> recorder = {};
        const std::set<char> pop = {')', ']', '}'};
        const std::unordered_map<char, char> push2pop = {
            {'(', ')'}, 
            {'[', ']'},
            {'{', '}'}
        };
        for (char c : s) {
            if (push2pop.find(c) != push2pop.end()) {
                recorder.push(c);
            }
            if (pop.find(c) != pop.end()) {
                if (recorder.size() == 0) { return false; }
                if (c != push2pop.at(recorder.top())) { return false; }
                recorder.pop();
            }
        }
        return recorder.size() == 0;
    }
};
