

/// Notes:
/// Just insert a new "()" into 0 index and each "(" right, 
/// to get an updated one.
///
/// Cases:
/// order = 2: ()(), (())
/// order = 3: 
///     For order = 2, ()(): ()()(), (())(), ()(())
///     For order = 2, (()): 
class Solution {
private:
    void update_parenthesis(
            std::queue<std::string>& holder, 
            const int32_t& order) {
        if (holder.size() == 0 && order == 1) { 
            holder.push("()"); 
            return;
        }
        std::unordered_map<std::string, int8_t> recorder = {}; 
        while (holder.front().size() == 2 * (order - 1)) {
            std::string curr = holder.front();
            holder.pop();
            for (int32_t i = 0; i < curr.size(); ++i) {
                std::string curr_new = "";
                if (i == 0) {
                   curr_new = "()" + curr; 
                } else {
                    if (curr.at(i - 1) == '(') {
                        curr_new = curr.substr(0, i) + "()" 
                                + curr.substr(i, curr.size() - i);
                    }
                }
                if (recorder.find(curr_new) == recorder.end()
                        && curr_new != "") { 
                    holder.push(curr_new); 
                    recorder[curr_new] = 1;
                }
            }
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        std::queue<std::string> holder = {};
        std::vector<std::string> results = {};
        for (int32_t i = 0;  i <= n; ++i) {
            update_parenthesis(holder, i);
        }
        while (holder.size() != 0) {
            results.emplace_back(holder.front());
            holder.pop();
        }
        return results; 
    }
};