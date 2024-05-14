use std::collections::HashMap;
use std::collections::HashSet;


impl Solution {
    pub fn unique_occurrences(arr: Vec<i32>) -> bool {
        let mut recorder: HashMap<i32, usize> = HashMap::new();
        let mut checker: HashSet<usize> = HashSet::new();
        for val in (&arr) {
            if !(&recorder).contains_key(&val) {
                recorder.insert(*val, 1);
            } else {
                recorder.entry(*val).and_modify(|count| *count += 1);
            }
        }
        for val in recorder.values() {
            if (&checker).contains(val) {
                return false;
            } 
            (&mut checker).insert(*val);
        }
        return true;
    }
}
