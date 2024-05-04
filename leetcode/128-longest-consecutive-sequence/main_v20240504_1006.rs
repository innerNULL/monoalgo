fn dbg_vec_print(vec: &Vec<i32>) {
    for x in vec {
        print!("{} ", x);
    }
    print!("\n");
}


impl Solution {
    pub fn longest_consecutive(mut nums: Vec<i32>) -> i32 {
        if (&nums).len() == 0 {
            return 0;
        }
        nums.sort_by(|a: &i32, b: &i32| a.cmp(b));
        //dbg_vec_print(&nums);
        let mut left_idx: usize = 0;
        let mut right_idx: usize = 1;
        let mut max_cons_nums: i32 = 1;
        let mut curr_cons_nums: i32 = 1;
        while right_idx < (&nums).len() {
            //println!("dbg: left_idx={}, right_idx={}", left_idx, right_idx);
            while (&nums)[right_idx] == (&nums)[right_idx - 1] + 1 
                || (&nums)[right_idx] == (&nums)[right_idx - 1]
            {   
                if (&nums)[right_idx] == (&nums)[right_idx - 1] + 1 {
                    curr_cons_nums += 1;
                }
                right_idx += 1;
                if right_idx == (&nums).len() {
                    break;
                }
            }
            max_cons_nums = std::cmp::max(
                max_cons_nums, curr_cons_nums
            );
            left_idx = right_idx;
            right_idx += 1;
            curr_cons_nums = 1;
        }
        return max_cons_nums;
    }
}
