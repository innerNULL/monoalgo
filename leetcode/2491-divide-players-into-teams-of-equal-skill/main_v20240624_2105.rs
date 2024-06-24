impl Solution {
    #[inline(always)]
    pub fn divide_players(mut skill: Vec<i32>) -> i64 {
        skill.sort();
        let mut teams: Vec<(i32, i32)> = Vec::new();
        for i in 0..skill.len() / 2 {
            let small: i32 = skill[i];
            let large: i32 = skill[skill.len() - 1 - i];
            if teams.len() > 0 {
                let last_group: &(i32, i32) = &teams[i - 1];
                let last_sum: i32 = (*last_group).0 + (*last_group).1;
                let curr_sum: i32 = small + large;
                if curr_sum != last_sum {
                    return -1;
                }
            }
            teams.push((small, large));
        }
        return teams
            .iter()
            .map(|x: &(i32, i32)| { return x.0 as i64 * x.1 as i64; })
            .sum();
    }
}
