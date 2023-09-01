class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        } else if (n == 1 || n == -1) {
            return n > 0 ? x : 1 / x;
        } else {
            bool neg_pow = n < 0;
            n = std::abs(n);
            double result_sqrt = myPow(x, n / 2);
            double result = result_sqrt * result_sqrt;
            result = n % 2 == 0 ? result: result * x;
            return neg_pow ? 1 / result : result;
        }
    }
};
