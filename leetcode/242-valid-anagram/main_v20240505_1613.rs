use std::collections::HashMap;


impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut recorder: HashMap<char, i32> = HashMap::new();
        for c in (&s).chars() {
            if !(&recorder).contains_key(&c) {
                (&mut recorder).insert(c, 0);
            }
            (&mut recorder).entry(c).and_modify(|v| *v = *v + 1);
        }
        for c in (&t).chars() {
            if !(&recorder).contains_key(&c) {
                return false;
            }
            (&mut recorder).entry(c).and_modify(|v| *v = *v - 1);
            match (&recorder).get(&c) {
                Some(x) => {
                    if *x < 0 { 
                        return false; 
                    }
                },
                _ => {}
            }
        }
        for (k, v) in (&recorder).iter() {
            if *v != 0 {
                return false;
            }
        }
        return true;
    }
}
