impl Solution {
    #[inline(always)]
    pub fn judge_circle(moves: String) -> bool {
        let mut x: i32 = 0;
        let mut y: i32 = 0;
        moves
            .chars()
            .for_each(
                |c: char| {
                    if c == 'U' {
                        x -= 1;
                    } else if c == 'D' {
                        x += 1;
                    } else if c == 'L' {
                        y -= 1;
                    } else if c == 'R' {
                        y += 1;
                    }
                    return;
                }
            );
        return x == 0 && y == 0; 
    }
}
