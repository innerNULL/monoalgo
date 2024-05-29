use std::collections::HashMap;


impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> Vec<i32> {
        let mut recorder: HashMap<i32, usize> = HashMap::new();
        for num in &nums {
            let entry: Option<&mut usize> = recorder.get_mut(&num);
            match entry {
                Some(x) => {
                    *x += 1;
                },
                None => {
                    recorder.insert(*num, 1);
                }
            }
        }
        let threshold: usize = nums.len() / 3;
        let mut cand_nums: Vec<i32> = nums
            .into_iter()
            .filter(|x: &i32| { *recorder.get(&x).unwrap() > threshold })
            .collect();
        cand_nums.sort();  
        cand_nums.dedup();
        return cand_nums;
    }
}
