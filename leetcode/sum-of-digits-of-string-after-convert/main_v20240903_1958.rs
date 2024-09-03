use std::collections::HashMap;


#[inline(always)]
fn vec_print(vec: &Vec<i32>) {
    for x in vec {
        print!("{} ", x);
    }
}


impl Solution {
    #[inline(always)]
    pub fn get_lucky(s: String, k: i32) -> i32 {
        let char2num: HashMap<char, i32> = [
            ('a', 1),
            ('b', 2),
            ('c', 3),
            ('d', 4),
            ('e', 5),
            ('f', 6),
            ('g', 7),
            ('h', 8),
            ('i', 9),
            ('j', 10),
            ('k', 11),
            ('l', 12),
            ('m', 13),
            ('n', 14),
            ('o', 15),
            ('p', 16),
            ('q', 17),
            ('r', 18),
            ('s', 19),
            ('t', 20),
            ('u', 21),
            ('v', 22),
            ('w', 23),
            ('x', 24),
            ('y', 25),
            ('z', 26),
        ].iter().cloned().collect();
        let mut digits: Vec<i32> = s
            .chars()
            .into_iter()
            .map(|x: char| { char2num.get(&x).unwrap().clone() })
            .map(|x: i32| { x.to_string() })
            .collect::<String>()
            .chars()
            .into_iter()
            .map(
                |x: char| { x.to_string().parse::<i32>().unwrap() }
            )
            .collect::<Vec<i32>>();
        for i in 0..(k as usize - 1) {
            digits = digits
                .into_iter()
                .sum::<i32>()
                .to_string()
                .chars()
                .into_iter()
                .map(
                    |x: char| { x.to_string().parse::<i32>().unwrap() }
                )
                .collect::<Vec<i32>>();
        }
        return digits.into_iter().sum::<i32>();
    }
}
