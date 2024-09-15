#[inline(always)]
fn mat_print(mat: &Vec<Vec<i32>>) {
    for vec in mat {
        for x in vec {
            print!("{} ", x);
        }
        print!("\n");
    }
}


#[inline(always)]
fn dp(
    dp_results: &mut Vec<Vec<i32>>,
    matrix: &Vec<Vec<char>>,
    row: usize, 
    col: usize
) {
    let row_num: usize = matrix.len();
    let col_num: usize = matrix[0].len();
    if row >= row_num || col >= col_num { return; }
    if dp_results[row][col] != -1 { return; }
    if row == 0 || col == 0 {
        dp_results[row][col] = {
            if matrix[row][col] == '0' {
                0
            } else {
                1
            }
        };
    } else {
        if matrix[row][col] == '0' {
            dp_results[row][col] = 0;
        } else {
            let left: i32 = dp_results[row][col - 1];
            let up: i32 = dp_results[row - 1][col];
            let left_up: i32 = dp_results[row - 1][col - 1];
            let min: i32 = std::cmp::min(
                std::cmp::min(left, up), left_up
            );
            dp_results[row][col] = 1 + min;
        }
    }
    return;
}


impl Solution {
    #[inline(always)]
    pub fn maximal_square(matrix: Vec<Vec<char>>) -> i32 {
        let mut dp_results: Vec<Vec<i32>> = vec![
            vec![-1; (&matrix)[0].len()]; 
            (&matrix).len()
        ]; 
        for row in 0..(&matrix).len() {
            for col in 0..(&matrix)[0].len() {
                dp(&mut dp_results, &matrix, row, col);
            }
        }
        //mat_print(&dp_results);
        let max: i32 = dp_results
            .into_iter()
            .map(|x: Vec<i32>| { x.into_iter().max().unwrap() })
            .max()
            .unwrap();
        return max * max;
    }
}
