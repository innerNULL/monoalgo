use std::collections::HashSet;
use std::fmt::Display;


lazy_static! {
    static ref VOWELS: HashSet<char> = {
        let mut set: HashSet<char> = HashSet::new();
        set.insert('a');
        set.insert('e');
        set.insert('i');
        set.insert('o');
        set.insert('u');
        set.insert('A');
        set.insert('E');
        set.insert('I');
        set.insert('O');
        set.insert('U'); 
        set
    };
}


unsafe fn string_chars_swap(s: &mut String, i: usize, j: usize) {
    let s_ptr: *mut u8 = s.as_mut_ptr();
    /*
    let c_2nd: char = *(s_ptr as *mut char).add(0); 
    let c_2nd_is_vowel: bool = VOWELS.contains(&c_2nd);
    println!("dbg: c_2nd={}", c_2nd);
    println!("dbg: c_2nd_is_vowel={}", c_2nd_is_vowel);
    */
    let tmp: char = (&s).chars().nth(j).unwrap();
    *s_ptr.add(j) = (&s).chars().nth(i).unwrap() as u8;
    *s_ptr.add(i) = tmp as u8;
    return;
}


fn dbg_vec_print<T: Display>(vec: &Vec<T>) {
    println!("dbg: Print vector");
    for x in vec {
        print!("{} ", x);
    }
    print!("\nEnd");
}


impl Solution {
    pub fn reverse_vowels(mut s: String) -> String {
        let mut vowels_idxs: Vec<usize> = Vec::new();
        for i in 0..(&s).len() {
            let c: char = (&s).chars().nth(i).unwrap();
            if VOWELS.contains(&c) {
                //println!("push: {}, {}", c, i);
                (&mut vowels_idxs).push(i);
            }
        }
        //println!("dbg: vowels_idxs.len()={}", vowels_idxs.len());
        //dbg_vec_print(&vowels_idxs);
        let mut left: usize = 0;
        let mut right: usize = (&vowels_idxs).len() - 1;
        while left < right {
            let left_idx: usize = (&vowels_idxs)[left];
            let right_idx: usize = (&vowels_idxs)[right];
            unsafe { string_chars_swap(&mut s, left_idx, right_idx); }
            left += 1;
            right -= 1;
        }
        return s;     
    }
}
