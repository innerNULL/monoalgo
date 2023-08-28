class Solution {
public:
    inline int mySqrt(int x) {
        if (x <= 1) { return x; }
        int64_t lower = 1;
        int64_t upper = x;
        int64_t mid = -1;
        while (lower < upper) {
            //printf("x=%i\n", x);
            //printf("lower=%i, upper=%i\n", lower, upper);
            mid = (lower + upper) / 2;
            int64_t mid_sqr = mid * mid;
            //printf("mid=%i, mid_sqr=%i\n", mid, mid_sqr);
            if (mid_sqr == x) {
                return mid;
            } else if (mid_sqr > x) {
                upper = mid;
            } else {
                lower = mid + 1;
            }
        }
        return mid * mid > x ? mid - 1 : mid; 
    }
};
