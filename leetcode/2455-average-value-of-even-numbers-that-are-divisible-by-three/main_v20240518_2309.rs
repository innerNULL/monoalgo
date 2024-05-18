impl Solution {
    pub fn average_value(nums: Vec<i32>) -> i32 {
        let target_nums: Vec<i32> = (&nums)
            .iter()
            .filter(|x| { x.clone() % 2 == 0 && x.clone() % 3 == 0 })
            .cloned()
            .collect();
        match (&target_nums).len() {
            0 => { 
                return 0; 
            },
            _ => {
                let sum: i32 = (&target_nums).iter().sum();
                return sum / ((&target_nums).len() as i32);
            }
        }
    }
}
