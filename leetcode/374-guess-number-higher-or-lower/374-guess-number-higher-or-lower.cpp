/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int64_t answer = -1;
        
        int64_t start_idx = 0;
        int64_t end_idx = n - 1;
        int64_t mid_idx = -1;
        int64_t mid_val = -1;
        
        while (true) {
            mid_idx = (start_idx + end_idx) / 2;
            mid_val = mid_idx + 1;
            //printf("dbg: %i, %i, %i\n", start_idx, end_idx, mid_idx);
            
            if (guess(mid_val) == 0) {
                return mid_val;
            } else if (guess(mid_val) == 1) { // smaller than target
                start_idx = mid_idx;
            } else { // larger than target
                end_idx = mid_idx;
            }
            if (start_idx == end_idx) { break; }
            if (start_idx == end_idx - 1) {
                if (guess(mid_val) == 1) {
                    start_idx = end_idx;
                }
            }
        }
        return mid_val;
    }
};