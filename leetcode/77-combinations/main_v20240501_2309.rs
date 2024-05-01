fn backtrack(
    results: &mut Vec<Vec<i32>>,
    curr_result: &mut Vec<i32>,
    n: i32, 
    k: usize, 
    start: i32
) {
    if curr_result.len() == k {
        results.push(curr_result.clone());
        return;
    }
    for i in start..=n {
        curr_result.push(i);
        backtrack(results, curr_result, n, k, i + 1);
        curr_result.pop();
    }
    return;
}


impl Solution {
    pub fn combine(n: i32, k: i32) -> Vec<Vec<i32>> {
        let mut results: Vec<Vec<i32>> = Vec::new();
        let mut curr_result: Vec<i32> = Vec::new();
        backtrack(
            &mut results, &mut curr_result, n, k as usize, 1
        );
        return results;
    }
}
