impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let mut coordinates: Vec<(usize, usize)> = Vec::new(); 
        for i in 0..matrix.len() {
            for j in 0..(&matrix[i]).len() {
                if matrix[i][j] == 0 { coordinates.push((i, j)); }
            }
        }
        for coordinate in &coordinates {
            //println!("dbg: x={}, y={}", coordinate.0, coordinate.1);
            for i in 0..matrix.len() {
                matrix[i][coordinate.1] = 0;
            }
            for j in 0..matrix[0].len() {
                matrix[coordinate.0][j] = 0;
            }
        }
    }
}
