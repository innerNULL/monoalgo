

inline std::string str_char_dedup(std::string str) {
    int32_t write_idx = 0;
    int32_t read_idx = 1;
    while (read_idx < str.size()) {
        if (str[read_idx] != str[write_idx]) {
            write_idx++;
            str[write_idx] = str[read_idx];
        }
        read_idx++;
    }
    return str.substr(0, write_idx + 1);
}


inline std::unordered_map<char, int32_t>
str2char_map(const std::string& str) {
    std::unordered_map<char, int32_t> map = {};
    for (int32_t i = 0;  i < str.size(); ++i) {
        if (map.find(str[i]) == map.end()) { map[str[i]] == 0; }
        map[str[i]]++;
    }
    return map;
}


class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        //std::cout << str_char_dedup(name) << std::endl;
        //std::cout << str_char_dedup(typed) << std::endl;
        if (str_char_dedup(name) != str_char_dedup(typed)) { return false; }
        std::unordered_map<char, int32_t> recorder1 = str2char_map(name);
        std::unordered_map<char, int32_t> recorder2 = str2char_map(typed);
        for (auto& pair : recorder1) {
            if (
                pair.second > recorder2[pair.first] 
                //|| recorder2[pair.first] % pair.second != 0
            ) { 
                return false; 
            }
        }
        return true;
    }
};
