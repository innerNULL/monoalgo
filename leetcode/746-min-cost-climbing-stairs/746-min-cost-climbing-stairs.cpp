
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int32_t back_2_steps_cost = cost[0];
        int32_t back_1_step_cost = cost[1];
        int32_t cost_to_curr_step = 0;

        for (int32_t i = 2; i < cost.size(); ++i) {
            cost_to_curr_step = std::min(
                back_1_step_cost, back_2_steps_cost) + cost[i];
            back_2_steps_cost = back_1_step_cost;
            back_1_step_cost = cost_to_curr_step; 
        }
        return std::min(back_1_step_cost, back_2_steps_cost);
    }
};