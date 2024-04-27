use std::cmp;


impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        //if (&strs).len() == 1 {
        //    return (&strs)[0].to_string();
        //}
        let mut min_size: usize = (&strs)
            .iter()
            .map(|x| { x.len() })
            .min()
            .unwrap();
        //println!("dbg: min_size={}", min_size);
        let mut max_idx: usize = 0;
        for i in 0..min_size {
            //println!("dbg: i={}", i);
            let c: char = (&strs)[0].chars().nth(i).unwrap();
            for s in (&strs) {
                if s.chars().nth(i).unwrap() != c {
                    //println!("dbg: {}.char({})={}", s, i, s.chars().nth(i).unwrap());
                    return (&strs)[0][0..i].to_string();
                }
            }
        }
        return (&strs)[0][0..min_size].to_string();
    }
}
