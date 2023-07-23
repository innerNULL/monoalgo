

void run_floodfill(
        std::vector<std::vector<int32_t> >& dest, 
        const std::vector<std::vector<int32_t> >& input, 
        int32_t sr, int32_t sc, int32_t color, int32_t start_color) {
    int32_t row_dim = input.size();
    int32_t col_dim = input[0].size();
    //printf("dbg: start\n");
    //printf("dbg: row_dim=%i, col_dim=%i\n", row_dim, col_dim);
    //printf("dbg: sr=%i, sc=%i\n", sr, sc);
    if ( (sr < 0 || sr >= row_dim) || (sc < 0 || sc >= col_dim) ) { 
        //printf("dbg: end case 0\n");
        return; 
    }
    if (input[sr][sc] != start_color || dest[sr][sc] == color) { 
        //printf("dbg: end case 1\n");
        return; 
    }
    dest[sr][sc] = color;
    
    int32_t next_upper_row = sr - 1;
    int32_t next_lower_row = sr + 1;
    int32_t next_left_col = sc - 1;
    int32_t next_right_col = sc + 1;
    //printf("dbg: next_upper_row=%i\n", next_upper_row);
    //printf("dbg: next_lower_row=%i\n", next_lower_row);
    //printf("dbg: next_left_col=%i\n", next_left_col);
    //printf("dbg: next_right_col=%i\n", next_right_col);
    
    //printf("dbg: run at (%i, %i)\n", next_upper_row, sc);
    run_floodfill(dest, input, next_upper_row, sc, color, start_color);
    run_floodfill(dest, input, next_lower_row, sc, color, start_color);
    run_floodfill(dest, input, sr, next_left_col, color, start_color);
    run_floodfill(dest, input, sr, next_right_col, color, start_color);
}


class Solution {
public:
    vector<vector<int>> floodFill(
            vector<vector<int>>& image, int sr, int sc, int color) {
        std::vector<std::vector<int32_t> > out = image;
        //image[sr][sc] = color;
        run_floodfill(out, image, sr, sc, color, image[sr][sc]);
        return out;
    }
};