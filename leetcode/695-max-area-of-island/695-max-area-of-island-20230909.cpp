

int32_t mark_island(vector<vector<int>>& grid, int32_t x, int32_t y) {
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) {
        return 0;
    }
    if (grid[x][y] != 1) { return 0; }
    int32_t area = 1;
    grid[x][y] = -1;
    area += mark_island(grid, x - 1, y);
    area += mark_island(grid, x, y - 1);
    area += mark_island(grid, x + 1, y);
    area += mark_island(grid, x, y + 1);
    return area;
}


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int32_t max_area = 0;
        for (int32_t i = 0; i < grid.size(); ++i) {
            for (int32_t j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) { 
                    int32_t area = mark_island(grid, i, j);
                    max_area = std::max(area, max_area);
                }
            }
        }
        return max_area;
    }
};
