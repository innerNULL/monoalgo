use std::collections::HashSet;


impl Solution {
    #[inline(always)]
    pub fn sort_vowels(mut s: String) -> String {
        let vowels: HashSet<char> = HashSet::from(
            ['A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u']
        );
        let mut curr_vowels: Vec<char> = s
            .clone()
            .chars()
            .into_iter()
            .filter(|x: &char| {return (&vowels).contains(&x);})
            .collect::<Vec<char>>();
        curr_vowels.sort();
        let mut idx: usize = 0;
        return s
            .chars()
            .collect::<Vec<char>>()
            .iter_mut()
            .map(
                |x: &mut char| { 
                    let mut out: char = x.clone();
                    if (&vowels).contains(x) {
                        out = (&curr_vowels)[idx].clone();
                        idx += 1;
                    } 
                    return out;
                }
            )
            .collect::<String>();
    }
}
