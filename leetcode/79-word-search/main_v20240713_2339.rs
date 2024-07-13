use std::collections::HashSet;


#[inline(always)]
fn dfs(
    board: &mut Vec<Vec<char>>,
    trace: &mut HashSet<(usize, usize)>,
    x: usize, 
    y: usize, 
    chars: &Vec<char>
) -> bool {
    if chars.len() == 0 {
        return true;
    }
    if (
        x < 0 || y < 0 
        || x >= board.len() || y >= board[0].len() 
        || board[x][y] != chars[0]
    ) {
        return false;
    }
    if trace.contains(&(x, y)) {
        return false;
    }
    trace.insert((x, y));
    let out: bool = {
        dfs(board, trace, x - 1, y, &chars[1..].to_vec()) 
        || dfs(board, trace, x + 1, y, &chars[1..].to_vec()) 
        || dfs(board, trace, x, y - 1, &chars[1..].to_vec()) 
        || dfs(board, trace, x, y + 1, &chars[1..].to_vec()) 
    };
    if out == false {
        trace.remove(&(x, y));
    }
    return out;
}


impl Solution {
    #[inline(always)]
    pub fn exist(
        mut board: Vec<Vec<char>>, 
        word: String
    ) -> bool {
        let chars: Vec<char> = word.chars().collect::<Vec<char>>();
        let mut flag: Vec<Vec<i8>> = vec![
            vec![0; board[0].len()]; board.len()
        ];
        let mut trace: HashSet<(usize, usize)> = HashSet::new();
        for x in 0..board.len() {
            for y in 0..board[0].len() {
                trace.clear();
                if dfs(
                    &mut board, 
                    &mut trace,
                    x, 
                    y, 
                    &chars
                ) {
                    return true;
                }
            }
        }
        return false;
    }
}
