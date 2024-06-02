use std::collections::HashMap;


impl Solution {
    #[inline(always)]
    pub fn equal_pairs(grid: Vec<Vec<i32>>) -> i32 {
        let mut rows: HashMap<Vec<i32>, i32> = HashMap::new();
        let row_num: usize = grid.len();
        let col_num: usize = (&grid)[0].len();
        for row_id in 0..row_num {
            let row: Vec<i32> = (&grid[row_id]).clone();
            let entry: Option<&mut i32> = rows.get_mut(&row);
            match entry {
                None => {
                    rows.insert(row, 1);
                },
                Some(x) => {
                    *x += 1;
                }
            }
        }

        let mut out: i32 = 0;
        for col_id in 0..col_num {
            let col: Vec<i32> = {
                let mut col: Vec<i32> = Vec::new();
                for row_id in 0..row_num {
                    col.push(grid[row_id][col_id]);
                }
                col
            };
            let entry: Option<&i32> = rows.get(&col);
            match entry {
                Some(x) => {
                    out += *x;
                },
                None => {}
            }
        }
        return out;
    }
}
