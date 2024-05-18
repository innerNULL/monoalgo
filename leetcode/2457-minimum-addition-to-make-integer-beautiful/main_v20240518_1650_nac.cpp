void int2digits(
    std::vector<int32_t>* const dest, int64_t n
) {
    int64_t divisor = 10;
    while (n > 0) {
        int64_t mod = n % divisor;
        dest->emplace_back((int32_t)mod);
        n /= divisor;
    }
    return;
}


void vec_print(const std::vector<int32_t>& vec) {
    for (auto x : vec) { printf("%i ", x); }
    printf("\n");
}


int32_t one_step(std::vector<int32_t>& digits) {
    int32_t carry = 1;
    size_t digit_idx = digits.size() - 1;
    int32_t diff = 0;
    while ((int32_t)digit_idx >= 0 && carry > 0) {
        vec_print(digits);
        printf("dbg (one_step): digit_idx=%i, carry=%i\n", digit_idx, carry);
        const int32_t digit = digits[digit_idx];
        const int32_t plused_digit = digit + carry;
        if (plused_digit >= 10) {
            carry = 1;
            digits[digit_idx] = plused_digit - 10;
        } else {
            digits[digit_idx] = plused_digit;
            carry = 0;
        }
        printf("dbg (one_step): %i to %i\n", digit, digits[digit_idx]);
        vec_print(digits);
        digit_idx -= 1;
        diff += (digit - digits[digit_idx]);
        printf("dbg (one_step): diff=%i\n", diff);
    }
    if (carry > 0) {
        const int32_t digit = digits[0];
        const int32_t plused_digit = digit + carry;
        if (plused_digit >= 10) {
            digits[0] = plused_digit - 10;
            digits.insert(digits.begin(), 1);
            diff += (0 - 1);
        } else {
            digits[0] = plused_digit;
        }
        diff += (digit - digits[0]);
    }
    return diff;
}


class Solution {
public:
    int64_t makeIntegerBeautiful(int64_t n, int32_t target) {
        std::vector<int32_t> digits = {};
        int2digits(&digits, n);
        std::reverse(digits.begin(), digits.end());
        int32_t digits_sum = std::reduce(
            digits.begin(), 
            digits.end(), 
            0, 
            [](int32_t prev, int32_t x) { return prev + x; }
        );
        if (digits_sum <= target) {
            return 0;
        }
        int32_t carry = 0;
        int32_t plus = 0;
        size_t digit_idx = digits.size() - 1;
        while (digits_sum > target) {
            digits_sum = digits_sum - one_step(digits);
            plus += 1;
            //vec_print(digits);
            //printf("dbg: digits_sum=%i, target=%i\n", digits_sum, target);
        }
        return plus;
    }
};
