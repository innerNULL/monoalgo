


std::string get_longest_palindrome(
        const std::string& str, 
        int32_t left_start_idx, int32_t right_start_idx) {
    int32_t before_num = left_start_idx;
    int32_t after_num = str.size() - 1 - right_start_idx;
    int32_t left_idx = left_start_idx;
    int32_t right_idx = right_start_idx;
    /*
    printf("info: start\n");
    printf("info: left_start_idx=%i\n", left_start_idx);
    printf("info: right_start_idx=%i\n", right_start_idx);
    printf("info: before_num=%i\n", before_num);
    printf("info: after_num=%i\n", after_num);
    */
    
    if (str.at(left_idx) != str.at(right_idx)) { return ""; }
    if (before_num == 0 || after_num == 0) {
        return str.substr(left_idx, right_idx - left_idx + 1);
    }
    
    while (before_num != 0 && after_num != 0) {
        if (str.at(left_idx) != str.at(right_idx)) { break; }
        left_idx--;
        right_idx++;
        before_num--;
        after_num--;
    }
    if (str.at(left_idx) != str.at(right_idx)) {
        left_idx++;
        right_idx--;
    }
    return str.substr(left_idx, right_idx - left_idx + 1);
}


class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 1) { return s; }
        if (s.size() == 0) { return ""; }
        
        std::string longest_palindrome = "";
        for (int32_t i = 0;  i < s.size(); ++i) {
            std::string odd_palindrome = "";
            std::string even_palindrome = "";
            
            odd_palindrome = get_longest_palindrome(s, i, i);
            if (i != s.size() - 1) {
                //printf("even case start\n");
                even_palindrome = get_longest_palindrome(s, i, i + 1);
            }
            
            if (odd_palindrome.size() > longest_palindrome.size()) {
                longest_palindrome = odd_palindrome;
            }
            if (even_palindrome.size() > longest_palindrome.size()) {
                longest_palindrome = even_palindrome;
            }
        }
        return longest_palindrome;
    }
};