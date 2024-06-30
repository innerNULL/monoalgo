use std::collections::HashSet;


#[inline(always)]
fn backtrack(
    results: &mut Vec<Vec<i32>>,
    buffer: &mut Vec<i32>,
    i: usize,
    candidates: &Vec<i32>,
    target: i32
) {
    //println!("(dbg) target={}", target);
    if target == 0 {
        results.push(buffer.clone());
        return;
    }
    if target < 0 {
        return;
    }
    for j in i..candidates.len() {
        buffer.push(candidates[j]);
        backtrack(
            results, 
            buffer, 
            j, 
            candidates, 
            target - candidates[j]
        );
        buffer.pop();
    }
}


impl Solution {
    #[inline(always)]
    pub fn combination_sum(
        mut candidates: Vec<i32>, 
        target: i32
    ) -> Vec<Vec<i32>> {
        let mut out: Vec<Vec<i32>> = Vec::new();
        let mut buffer: Vec<i32> = Vec::new();
        candidates = candidates
            .iter()
            .map(|x: &i32| { return x.clone(); })
            .collect::<HashSet<i32>>()
            .iter()
            .map(|x: &i32| { return x.clone(); })
            .collect::<Vec<i32>>();
        backtrack(&mut out, &mut buffer, 0, &candidates, target);
        return out;
    }
}
