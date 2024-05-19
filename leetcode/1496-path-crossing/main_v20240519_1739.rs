use std::collections::HashSet;


impl Solution {
    pub fn is_path_crossing(path: String) -> bool {
        let mut traces: HashSet<Vec<i32>> = HashSet::new();
        let mut last_loc: Vec<i32> = vec![0, 0];
        traces.insert(last_loc.clone());
        for c in path.chars() {
            if c == 'N' {
                (&mut last_loc)[1] += 1;
            } else if c == 'S' {
                (&mut last_loc)[1] -= 1;
            } else if c == 'W' {
                (&mut last_loc)[0] -= 1;
            } else if c == 'E' {
                (&mut last_loc)[0] += 1;
            }
            if (&traces).contains(&last_loc) {
                return true;
            } else {
                (&mut traces).insert(last_loc.clone());
            }
        }
        return false;
    }
}
