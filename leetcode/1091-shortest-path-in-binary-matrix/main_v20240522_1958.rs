use std::collections::VecDeque;

impl Solution {
    pub fn shortest_path_binary_matrix(mut grid: Vec<Vec<i32>>) -> i32 {
        let mv_directions: Vec<(i32, i32)> = vec![
            // row, col
            (-1, 0),
            (0, -1),
            (1, 0), 
            (0, 1),
            (1, 1),
            (-1, -1),
            (-1, 1),
            (1, -1)
        ];
        let row_num: usize = (&grid).len();
        let col_num: usize = (&grid)[0].len();
        if (
            (&grid)[0][0] == 1 
            || (&grid)[row_num - 1][col_num - 1] == 1
        ) {
            return -1
        }
        if row_num == 1 && col_num == 1 && (&grid)[0][0] == 0 {
            return 1;
        }
        // (distance, row, col)
        let mut tasks: VecDeque<(i32, i32, i32)> = VecDeque::new();
        tasks.push_back((1, 0, 0));
        while (&tasks).len() > 0 {
            let (dist, row, col): (i32, i32, i32) = {
                *tasks.front().unwrap()
            };
            tasks.pop_front();
            for shift in &mv_directions {
                let next_row: i32 = row + shift.0;
                let next_col: i32 = col + shift.1;
                if (
                    next_row < row_num as i32 && next_col < col_num as i32
                    && next_row >= 0 && next_col >= 0
                    && (&grid)[next_row as usize][next_col as usize] == 0
                ) {
                    (&mut grid)[next_row as usize][next_col as usize] = -1;
                    if (
                        next_row == row_num as i32 - 1 
                        && next_col == col_num as i32 - 1
                    ) {
                        return dist + 1;
                    }
                    (& mut tasks).push_back(
                        (dist + 1, next_row, next_col)
                    );
                }
            }
        }
        return -1;
    }
}
