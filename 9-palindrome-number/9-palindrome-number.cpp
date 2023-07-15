#include <vector>

class Solution {    
public:
    bool isPalindrome(int x) {
        if (x < 0) { 
            return false; 
        } else if (x >= 0 and x <= 0) {
            return true;
        } else {
            std::vector<int> recorder;
            int tmp = x;
            int remainder = 0;
            int divisor = 10;
            while (tmp > 0) {
                remainder = tmp % divisor;
                tmp = (tmp - remainder) / divisor;
                recorder.emplace_back(remainder);
            }

            // Check if palindrome
            int left_idx = 0;
            int right_idx = recorder.size() - 1;
            while (left_idx <= right_idx) {
                if (recorder[left_idx] != recorder[right_idx]) {
                    return false;
                }
                left_idx++;
                right_idx--;
            }
            return true;
        }
    }
};
