impl Solution {
    #[inline(always)]
    pub fn three_consecutive_odds(arr: Vec<i32>) -> bool {
        let mut odds: Vec<(usize, i32)> = arr
            .iter()
            .enumerate()
            .filter(|x: &(usize, &i32)| { return (*x.1) % 2 != 0; })
            .map(|x: (usize, &i32)| { return (x.0, x.1.clone()); })
            .collect::<Vec<(usize, i32)>>();
        let mut cnt: i32 = 1;
        for i in 1..odds.len() {
            let curr_odd: (usize, i32) = (&odds)[i];
            let last_odd: (usize, i32) = (&odds)[i - 1];
            if curr_odd.0 - 1 == last_odd.0 {
                cnt += 1;
            } else {
                cnt = 1;
            }
            if cnt == 3 {
                return true;
            }
        }
        return false;
    }
}
