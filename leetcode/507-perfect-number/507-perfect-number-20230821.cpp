class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) { return false; }
        std::set<int32_t> recorder = {};
        int32_t sum = 0;
        int32_t divisor = 1;
        while (true) {
            if (num % divisor != 0) {
                divisor++;
            } else if (
               num % divisor == 0 && recorder.find(divisor) == recorder.end()
            ) {
               recorder.insert(divisor);
               recorder.insert(num / divisor);
               //printf("%i, %i\n", divisor, num / divisor);
               divisor++;
            } else {
                break;
            }
        } 
        return std::accumulate(
            recorder.begin(), recorder.end(), 0) - num == num;
    }
};
