class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int32_t max_val = 0;
        for (int32_t i = 0; i < grid.size(); ++i) {
            for (int32_t j = 0; j < grid[i].size(); ++j) {
                max_val = std::max(max_val, this->dfs(grid, i, j));
            }
        } 
        return max_val;
    }

    int32_t dfs(
        std::vector<std::vector<int32_t>>& grid, int32_t x, int32_t y
    ) {
        if (x < 0 || y < 0 
            || x >= grid.size() || y >= grid[x].size() 
            || grid[x][y] <= 0
        ) {
            return 0;
        }
        int32_t curr_val = grid[x][y];
        grid[x][y] = -1;
        int32_t best_rest = std::max({
            this->dfs(grid, x + 1, y), this->dfs(grid, x, y + 1), 
            this->dfs(grid, x - 1, y), this->dfs(grid, x, y - 1)
        });
        grid[x][y] = curr_val;
        return curr_val + best_rest;
    }
};
