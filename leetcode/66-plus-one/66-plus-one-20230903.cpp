class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int32_t carry = 0;
        for (int32_t i = digits.size() - 1; i >= 0; --i) {
            int32_t plus = i == digits.size() - 1 ? 
                digits[i] + 1 + carry : digits[i] + carry;
            if (plus == 10) {
                carry = 1;
                plus = 0;
            } else {
                carry = 0;
            }
            digits[i] = plus;
        }
        if (carry == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
