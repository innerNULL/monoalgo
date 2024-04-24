use std::cmp;
use std::collections::HashMap;


struct Context {
    dup_keys: u32,
    counter: HashMap<char, u32>,
}


unsafe fn Context_register(ctx: *mut Context, c: char) {
    let counter: &mut HashMap<char, u32> = &mut (*ctx).counter;
    counter.entry(c)
        .and_modify(|x| { (*x) += 1 })
        .or_insert(1);
    if counter[&c] > 1 {
        (*ctx).dup_keys += 1;
    }
    return;
}


unsafe fn Context_deregister(ctx: *mut Context, c: char) {
    let counter: &mut HashMap<char, u32> = &mut (*ctx).counter;
    counter.entry(c)
        .and_modify(
            |x| { 
                (*x) -= 1;
                cmp::max((*x), 0);
            }
        ).or_insert(0);
    if counter[&c] == 1 {
        (*ctx).dup_keys -= 1;
    }
    return;
}


unsafe fn Context_has_dup(ctx: *mut Context) -> bool {
    return ((*ctx).dup_keys != 0);
}


impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        if s.len() <= 1 { 
            return s.len() as i32; 
        } else if s.len() == 2 {
            return {
                let mut out: i32 = 1;
                if (&s).chars().nth(1) != (&s).chars().nth(0) {
                    out += 1;
                }
                out
            }
        }

        let mut ctx: Context = Context {
            dup_keys: 0, counter: HashMap::new()
        };
        let mut left_idx: usize = 0;
        let mut right_idx: usize = 1;
        let mut max_len: usize = 0;

        unsafe {
            Context_register(
                &mut ctx as *mut Context, (&s).chars().nth(left_idx).unwrap()
            );
            while right_idx < s.len() {
                if right_idx == left_idx { right_idx += 1; }
                if right_idx >= s.len() { break; }
                while !Context_has_dup(&mut ctx as *mut Context) {
                    Context_register(
                        &mut ctx as *mut Context, 
                        (&s).chars().nth(right_idx).unwrap()
                    );
                    max_len = cmp::max(max_len, right_idx - left_idx);
                    right_idx += 1;
                }
                while Context_has_dup(&mut ctx as *mut Context) {
                    Context_deregister(
                        &mut ctx as *mut Context, 
                        (&s).chars().nth(left_idx).unwrap()
                    );
                    left_idx += 1;
                    if left_idx == right_idx { break; }
                }
            }
        }
        return max_len as i32;   
    }
}
