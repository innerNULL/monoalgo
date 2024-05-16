impl Solution {
    pub fn max_product_path(grid: Vec<Vec<i32>>) -> i32 {
        let mut dp_max: Vec<Vec<i64>> = vec![
            vec![-1; (&grid)[0].len()]; (&grid).len()
        ]; 
        let mut dp_min: Vec<Vec<i64>> = vec![
            vec![0 as i64; (&grid)[0].len()]; (&grid).len()
        ]; 
        (&mut dp_max)[0][0] = (&grid)[0][0] as i64;
        (&mut dp_min)[0][0] = (&grid)[0][0] as i64;
        for row in 1..(&grid).len() {
            (&mut dp_max)[row][0] = {
                (&dp_max)[row - 1][0] as i64 * (&grid)[row][0] as i64
            };
            (&mut dp_min)[row][0] = {
                (&dp_min)[row - 1][0] as i64 * (&grid)[row][0] as i64
            };
        }
        for col in 1..(&grid)[0].len() {
            (&mut dp_max)[0][col] = {
                (&dp_max)[0][col - 1] as i64 * (&grid)[0][col] as i64
            };
            (&mut dp_min)[0][col] = {
                (&dp_min)[0][col - 1] as i64 * (&grid)[0][col] as i64
            };
        }
        for row in 1..(&grid).len() {
            for col in 1..(&grid)[0].len() {
                if (&grid)[row][col] >= 0 {
                    (&mut dp_max)[row][col] = std::cmp::max(
                        (&dp_max)[row - 1][col] * (&grid)[row][col] as i64,
                        (&dp_max)[row][col - 1] * (&grid)[row][col] as i64
                    );
                    (&mut dp_min)[row][col] = std::cmp::min(
                        (&dp_min)[row - 1][col] * (&grid)[row][col] as i64,
                        (&dp_min)[row][col - 1] * (&grid)[row][col] as i64
                    );
                } else {
                    (&mut dp_max)[row][col] = std::cmp::max(
                        (&dp_min)[row - 1][col] * (&grid)[row][col] as i64,
                        (&dp_min)[row][col - 1] * (&grid)[row][col] as i64
                    );
                    (&mut dp_min)[row][col] = std::cmp::min(
                        (&dp_max)[row - 1][col] * (&grid)[row][col] as i64,
                        (&dp_max)[row][col - 1] * (&grid)[row][col] as i64
                    );
                }
            }
        }
        if (&dp_max)[(&grid).len() - 1][(&grid)[0].len() - 1] < 0 {
            return -1
        }
        return {
            (
                (&dp_max)[(&grid).len() - 1][(&grid)[0].len() - 1] 
                % 1000000007
            ) as i32
        };
    }
}
