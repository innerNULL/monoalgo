class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::vector<std::string> num_strs = {};
        for (int32_t num : nums) {
            num_strs.emplace_back(std::to_string(num));
        }
        std::sort(
            num_strs.begin(), num_strs.end(),
            [](const std::string& a, const std::string& b) {
                return a + b > b + a;
            }
        );
        std::string result = "";
        for (auto& str : num_strs) {
            result += str;
        }
        return result[0] == '0' ? "0" : result;
    }
};
