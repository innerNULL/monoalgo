class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int32_t profit = 0;
       for (int32_t i = 1; i < prices.size(); ++i) {
           if (prices[i] > prices[i - 1]) {
               profit += (prices[i] - prices[i - 1]);
           }
       } 
       return profit;
    }
};
