use std::fmt::Display;


fn vec_print<T: Display>(vec: &Vec<T>) {
    for x in vec {
        print!("{} ", x);
    }
    print!("\n");
}


impl Solution {
    pub fn good_indices(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut dp_left_cons_inc: Vec<i32> = vec![0; (&nums).len()];
        let mut dp_right_cons_desc: Vec<i32> = vec![0; (&nums).len()];
        dp_left_cons_inc[1] = 1;
        dp_right_cons_desc[(&nums).len() - 2] = 1;
        for i in 2..(&nums).len() {
            if nums[i - 2] >= nums[i - 1] {
                dp_left_cons_inc[i] = dp_left_cons_inc[i - 1] + 1;
            } else {
                dp_left_cons_inc[i] = 1;
            }
        }
        for i in (0..(&nums).len() - 2).rev() {
            if nums[i + 2] >= nums[i + 1] {
                dp_right_cons_desc[i] = dp_right_cons_desc[i + 1] + 1;
            } else {
                dp_right_cons_desc[i] = 1;
            }
        }
        //vec_print(&dp_left_cons_inc);
        //vec_print(&dp_right_cons_desc);
        let mut out: Vec<i32> = Vec::new();
        for i in 0..(&nums).len() {
            if dp_left_cons_inc[i] >= k && dp_right_cons_desc[i] >= k {
                out.push(i as i32);
            }
        }
        return out;
    }
}
