#include <vector>


inline constexpr void 
mat_print(std::vector<std::vector<char>>& mat) {
    for (auto x : mat) {
        for (auto y : x) {
            printf("%c ", y);
        }
        printf("\n");
    } 
    return;
}


// The idea is quite simple:
// * Mark all 'O' on edge of the matrix with non 'O' or 'X' char, 
//   for example '#', also mark all 'O' which can directly or 
//   indirectly connect with 'O's on edge. 
// * Update all non '#' elements in matrix to 'X'
// * Update all '#' elements in matrix to 'O'
// Done! 
inline constexpr void 
mat_rmark(
    std::vector<std::vector<char>>& mat, 
    size_t row, 
    size_t col, 
    char new_val, 
    char target_val
) {
    if (
        row < 0 || col < 0 
        || row >= mat.size() || col >= mat[0].size()
    ) {
        return;
    }
    if (mat[row][col] == target_val) {
        mat[row][col] = new_val;
        mat_rmark(mat, row + 1, col, new_val, target_val);
        mat_rmark(mat, row - 1, col, new_val, target_val);
        mat_rmark(mat, row, col + 1, new_val, target_val);
        mat_rmark(mat, row, col - 1, new_val, target_val);
    }
    return;
}


class Solution {
public:
    inline constexpr void 
    solve(std::vector<std::vector<char>>& board) {
        for (size_t row = 0; row < board.size(); ++row) {
            mat_rmark(board, row, 0, '#', 'O');
            mat_rmark(board, row, board[0].size() - 1, '#', 'O');
        }
        for (size_t col = 0; col < board[0].size(); ++col) {
            mat_rmark(board, 0, col, '#', 'O');
            mat_rmark(board, board.size() - 1, col, '#', 'O');
        }
        //mat_print(board);
        for (size_t row = 0; row < board.size(); ++row) {
            for (size_t col = 0; col < board[0].size(); ++col) {
                if (board[row][col] != '#') {
                    board[row][col] = 'X';
                } else {
                    board[row][col] = 'O';  
                }
            }
        }
        return;
    }
};
