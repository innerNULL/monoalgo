auto right_max = [] (
    std::vector<int32_t>& dest, 
    const std::vector<int32_t>& prices
) -> void {
    for (int32_t i = prices.size() - 1; i >= 0; --i) {
        if (i == prices.size() - 1) {
            dest[i] = prices[i];
        } else {
            dest[i] = std::max(prices[i + 1], dest[i + 1]);
        }
    }
    return;
};


auto print_vec = [] (const std::vector<int>& vec) {
    for (int x : vec) {
        printf("%i ", x);
    }
    printf("\n");
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        std::vector<int32_t> right_max_val(prices.size(), 0);
        right_max(right_max_val, prices);
        //print_vec(right_max_val);
        int max_return = INT_MIN;
        for (int32_t i = 0; i < prices.size(); ++i) {
            max_return = std::max(
                max_return, right_max_val[i] - prices[i]
            );
        }
        return max_return;
    }
};
