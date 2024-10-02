#include <vector>

using std::vector;


inline constexpr void
vector_print(const vector<int32_t>& vec) {
    for (auto x : vec) {
        printf("%i ", x);
    }
    return;
}


class Solution {
public:
    inline constexpr int32_t 
    maxProfit(const vector<int32_t>& prices) {
        const size_t num = prices.size();
        if (num <= 1) { return 0; }
        vector<int32_t> future_max(num, 0);
        future_max[num - 1] = prices[num - 1];
        for (size_t i = num - 2; i > 0; --i) {
            future_max[i] = std::max(
                future_max[i + 1], prices[i + 1]
            );
        }
        future_max[0] = std::max(future_max[1], prices[1]);
        //vector_print(future_max);
        int32_t out = 0;
        for (size_t i = 0; i < num; ++i) {
            out = std::max(out, future_max[i] - prices[i]);
        }
        return out;
    }
};
