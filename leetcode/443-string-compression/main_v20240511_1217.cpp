#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")


#include <map>


class Solution {
public:
    int compress(vector<char>& chars) {
        size_t writer = 1;
        char last_char = chars[0];
        size_t last_char_cnt = 1;
        for (size_t reader = 1; reader < chars.size(); ++reader) {
            //printf("%i, %i\n", reader, writer);
            char curr_char = chars[reader];
            if (curr_char == last_char) {
                last_char_cnt += 1;
            } else {
                if (last_char_cnt > 1) {
                    for (auto c : std::to_string(last_char_cnt)) {
                        chars[writer] = c;
                        writer += 1;
                    }
                }
                chars[writer] = curr_char;
                writer += 1;
                last_char = curr_char;
                last_char_cnt = 1;
            }
        }
        //printf("dbg: last_char_cnt=%i", last_char_cnt);
        if (last_char_cnt > 1) {
            for (auto c : std::to_string(last_char_cnt)) {
                chars[writer] = c;
                writer += 1;
            }
        }
        return writer;
    }
};
