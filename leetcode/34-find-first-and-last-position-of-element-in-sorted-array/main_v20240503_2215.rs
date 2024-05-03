fn dbg_vec_print(vec: &Vec<i32>) {
    for x in vec {
        print!("{} ", x);
    }
    print!("\n");
}


fn search_left_or_right_most(
    nums: &Vec<i32>, target: i32, left_most: bool
) -> i32 {
    let mut out: i32 = -1;
    let mut left_idx: i32 = 0;
    let mut right_idx: i32 = (nums.len() - 1) as i32;
    while left_idx <= right_idx {
        let mid_idx: i32 = (left_idx + right_idx) / 2;
        let mid_val: i32 = nums[mid_idx as usize];
        let left_val: i32 = nums[left_idx as usize];
        let right_val: i32 = nums[right_idx as usize];
        if mid_val < target {
            left_idx = mid_idx + 1;
        } else if mid_val > target {
            right_idx = mid_idx - 1;
        } else {
            out = mid_idx;
            match left_most {
                true => {
                    right_idx = mid_idx - 1;
                },
                false => {
                    left_idx  = mid_idx + 1;
                },
            }
        }
    }
    return out;
}


impl Solution {
    pub fn search_range(
        nums: Vec<i32>, target: i32
    ) -> Vec<i32> {
        match (&nums).len() {
            0 => {
                return vec![-1, -1];
            },
            1 => {
                return {
                    if (&nums)[0] == target {
                        vec![0, 0]
                    } else {
                        vec![-1, -1]
                    }
                };
            },
            _ => {}
        }
        let left_most_idx: i32 = search_left_or_right_most(
            &nums, target, true
        );
        let right_most_idx: i32 = search_left_or_right_most(
            &nums, target, false
        );
        /*
        dbg_vec_print(&nums);
        println!(
            "dbg: left_most_idx={}, right_most_idx={}",
            left_most_idx,
            right_most_idx
        );
        */
        return vec![left_most_idx, right_most_idx];
    }
}
