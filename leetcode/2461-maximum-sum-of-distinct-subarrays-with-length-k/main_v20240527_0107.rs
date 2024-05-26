use std::collections::HashMap;


struct Context {
    num_cnts: HashMap<i32, i32>,
    dup_cnt: i32,
    sum: i64
}


impl Context {
    fn push(&mut self, val: i32) {
        let entry: Option<&mut i32> = self.num_cnts.get_mut(&val);
        match entry {
            Some(x) => { 
                *x += 1; 
                if *x > 1 {
                    self.dup_cnt += 1;
                }
            },
            _ => { 
                self.num_cnts.insert(val, 1); 
            }
        }
        self.sum += val as i64;
    }

    fn pop(&mut self, val: i32) {
        let entry: Option<&mut i32> = self.num_cnts.get_mut(&val);
        match entry {
            Some(x) => {
                if *x > 0 { 
                    *x -= 1; 
                    self.sum -= val as i64;
                }
                if *x != 0 {
                    self.dup_cnt -= 1; 
                }
            },
            _ => {}
        }
    }
}


fn dbg_vec_print(vec: &Vec<i32>) {
    for x in vec {
        print!("{} ", x);
    }
    print!("\n");
}


impl Solution {
    pub fn maximum_subarray_sum(nums: Vec<i32>, k: i32) -> i64 {
        if k == 1 {
            return nums.iter().max().unwrap().clone() as i64;
        }
        let mut ctx: Context = Context {
            num_cnts: HashMap::new(), dup_cnt: 0, sum: 0
        };
        let mut max_sum: i64 = 0;
        for i in 0..k as usize { 
            (&mut ctx).push((&nums)[i]); 
        }
        if (&ctx).dup_cnt == 0 {
            max_sum = std::cmp::max(max_sum, (&ctx).sum);
        }
        //dbg_vec_print(&nums[0..k as usize].to_vec());
        //println!("(dbg) ctx.sum={}, ctx.dup_cnt={}", ctx.sum, ctx.dup_cnt);
        if k as usize >= nums.len() {
            return max_sum;
        }
        for right_idx in k as usize..(&nums).len() {
            let left_idx: usize = right_idx - k as usize + 1;
            (&mut ctx).pop(nums[left_idx - 1]);
            (&mut ctx).push(nums[right_idx]);
            //dbg_vec_print(&nums[left_idx..=right_idx].to_vec());
            //println!("(dbg) ctx.sum={}, ctx.dup_cnt={}", ctx.sum, ctx.dup_cnt);
            if (&ctx).dup_cnt == 0 {
                max_sum = std::cmp::max(max_sum, (&ctx).sum.clone());
            }
        }
        return max_sum;
    }
}
