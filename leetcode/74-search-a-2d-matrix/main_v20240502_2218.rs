impl Solution {
    pub fn search_matrix(
        matrix: Vec<Vec<i32>>, target: i32
    ) -> bool {
        let row_num: usize = (&matrix).len();
        let col_num: usize = (&matrix[0]).len();
        let mut row_idx: usize = 0;
        let mut col_idx: usize = col_num - 1;
        while row_idx < row_num && col_idx < col_num {
            let val: i32 = (&matrix)[row_idx][col_idx];
            if target == val {
                return true;
            } else if (target > val) {
                row_idx += 1;
            } else {
                col_idx -= 1;
            }
        }
        return false;
    }
}
