

std::vector<int32_t>* get_right_max(vector<int>& input) {
    std::vector<int32_t>* out = new std::vector<int32_t>();
    out->resize(input.size());
    
    (*out)[input.size() - 1] = 0;
    (*out)[input.size() - 2] = input[input.size() - 1];
    for (int32_t i = input.size() - 3; i >= 0; --i) {
        (*out)[i] = std::max(input[i + 1], (*out)[i + 1]);
    }
    return out;
}


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) { return 0; }
        
        int32_t max_profit = 0;
        std::vector<int32_t>* right_max = get_right_max(prices);
        for (int32_t i = 0; i <= prices.size() - 2; ++i) {
            int32_t curr_price = prices[i];
            int32_t curr_right_max = (*right_max)[i];
            int32_t curr_max_profix = curr_right_max - curr_price;
            if (curr_max_profix > max_profit) {
                max_profit = curr_max_profix;
            }
        }
        return max_profit;
    }
};