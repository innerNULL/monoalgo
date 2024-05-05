use std::collections::HashMap;


impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        let mut recorder: HashMap<i32, usize> = HashMap::new();
        for i in 0..(&nums).len() {
            let x: i32 = (&nums)[i];
            if !(&recorder).contains_key(&x) {
                (&mut recorder).insert(x, i);
            } else {
                match (&recorder).get(&x) {
                    Some(last_idx) => {
                        if i - last_idx <= (k as usize) {
                            return true;
                        } else {
                            (&mut recorder)
                                .entry(x)
                                .and_modify(|v| *v = i);
                        }
                    },
                    _ => {}
                }
            }
        }
        return false;
    }
}
