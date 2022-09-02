

std::string get_common_prefix(
        const std::string& str1, const std::string& str2) {
    int32_t common_prefix_idx = 0;
    if (str1.size() == 0 || str2.size() == 0) { return ""; }
    while (common_prefix_idx < str1.size() 
            && common_prefix_idx < str2.size() ) {
        if (str1.at(common_prefix_idx) != str2.at(common_prefix_idx)) {
            break;
        }
        common_prefix_idx += 1;
    }
    return str1.substr(0, common_prefix_idx);
}


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) { return ""; }
        if (strs.size() == 1) { return strs[0]; }
        
        std::string longest_comm_prefix = strs[0];
        //std::string a = "123";
        //std::string b = "12";
        //std::cout << get_common_prefix(a, b) << std::endl;
        
        for (int32_t i = 1; i < strs.size(); ++i) {
            longest_comm_prefix = get_common_prefix(
                longest_comm_prefix, strs[i]);
        }
        
        return longest_comm_prefix;
    }
};