use std::collections::HashMap;


impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut results: Vec<i32> = Vec::new();
        let mut recorder: HashMap<i32, i32> = HashMap::new();
        for i in (0..nums.len()) {
            let left: i32 = target - nums[i];
            if recorder.contains_key(&left) {
                results.push(recorder[&left]);
                results.push(i as i32);
                return results;
            }
            if !recorder.contains_key(&nums[i]) {
                recorder.insert(nums[i], i as i32);
            }
        }
        return results;
    }
}