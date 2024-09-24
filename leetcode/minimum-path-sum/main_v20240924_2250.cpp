#include <vector>


inline constexpr int32_t run(
    const std::vector<std::vector<int32_t>>& grid,
    std::vector<std::vector<int32_t>>& cache, 
    const size_t start_row, 
    const size_t start_col
) {
    const size_t rows_cnt = grid.size();
    const size_t cols_cnt = grid[0].size();
    if (
        start_row >= rows_cnt 
        || start_col >= cols_cnt
    ) {
        return 0;
    } else if (cache[start_row][start_col] != -1) {
        return cache[start_row][start_col];
    } else if (start_row == rows_cnt - 1) {
        int32_t result = (
            grid[start_row][start_col] 
            + run(grid, cache, start_row, start_col + 1)
        );
        cache[start_row][start_col] = result;
        return result;
    } else if (start_col == cols_cnt - 1) {
        int32_t result = (
            grid[start_row][start_col] 
            + run(grid, cache, start_row + 1, start_col)
        );
        cache[start_row][start_col] = result;
        return result;
    } else {
        int32_t result = (
            grid[start_row][start_col] + std::min(
                run(grid, cache, start_row + 1, start_col),
                run(grid, cache, start_row, start_col + 1)
            )
        );
        cache[start_row][start_col] = result;
        return result;
    }
}


class Solution {
public:
    inline constexpr int32_t 
    minPathSum(const std::vector<std::vector<int32_t>>& grid) {
        std::vector<std::vector<int32_t>> cache(
            grid.size(), 
            std::vector<int>(grid[0].size(), -1)
        );
        return run(grid, cache, 0, 0);
    }
};
