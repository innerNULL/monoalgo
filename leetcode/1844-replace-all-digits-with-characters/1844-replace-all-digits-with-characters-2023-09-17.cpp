#include <string>  
#include <iostream>


const std::vector<char> letters = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};


typedef struct CharMap {
    std::unordered_map<char, int32_t> char2id = {};
    std::unordered_map<int32_t, char> id2char = {};
} CharMap;


inline void charmap_insert(CharMap* char_map, char letter, int32_t id) {
    std::unordered_map<char, int32_t>& char2id = char_map->char2id;
    std::unordered_map<int32_t, char>& id2char = char_map->id2char;
    if (char2id.find(letter) == char2id.end()) {
        char2id[letter] = id;
        id2char[id] = letter;
    }
}


inline void charmap_init(CharMap* char_map) {
    for (int32_t i = 0; i < letters.size(); ++i) {
        charmap_insert(char_map, letters[i], i);
    }
}


class Solution {
public:
    inline std::string replaceDigits(std::string& s) {
        CharMap* char_map = new CharMap();
        charmap_init(char_map);
        for (int32_t i = 0; i < s.size(); ++i) {
            if (i % 2 != 0) { continue; }
            if (i + 1 < s.size()) {
                int32_t shift_id = s[i + 1] - '0';
                char curr_char = s[i];
                char shift_char = char_map->id2char[
                    char_map->char2id[curr_char] + shift_id
                ];
                //printf("i=%i\n", i);
                //printf("shift_id=%i\n", shift_id);
                //printf("curr_char=%c\n", curr_char);
                s[i + 1] = shift_char;
            }
        }
        return s;
    }
};
