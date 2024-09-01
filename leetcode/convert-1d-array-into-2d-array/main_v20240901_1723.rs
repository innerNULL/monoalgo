impl Solution {
    #[inline(always)]
    pub fn construct2_d_array(
        original: Vec<i32>, 
        m: i32, 
        n: i32
    ) -> Vec<Vec<i32>> {
        if m * n != original.len() as i32 {
            return Vec::new();
        }
        let mut out: Vec<Vec<i32>> = {
            vec![vec![0; n as usize]; m as usize]
        };
        let mut row: usize = 0;
        for i in 0..original.len() {
            let col: usize = ((i as i32) % n) as usize;
            if col == 0 && i != 0 {
                row += 1;
            }
            //println!("row={}, col={}, idx={}", row, col, i);
            //println!("out.row={}, out.col={}", out.len(), out[0].len());
            out[row][col] = original[i];
        }
        return out;
    }
}
