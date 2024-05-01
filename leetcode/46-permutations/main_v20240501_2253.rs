fn extend(
    results: &mut Vec<Vec<i32>>,
    new_num: i32
) -> Vec<Vec<i32>> {
    let mut next_results: Vec<Vec<i32>> = Vec::new();
    let curr_len: usize = results.len();
    for i in 0..curr_len {
        let curr_result: &mut Vec<i32> = &mut results[i];
        for j in 0..=curr_result.len() {
            let mut new_result: Vec<i32> = curr_result.clone();
            new_result.insert(j, new_num);
            next_results.push(new_result);
        }
    }
    return next_results;
}


impl Solution {
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut results: Vec<Vec<i32>> = vec![vec![nums[0]]];
        for num in nums[1..].iter() {
            results = extend(&mut results, *num);
        }
        return results;
    }
}
