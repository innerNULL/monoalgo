use std::cmp;


fn vec_print(vec: &Vec<i32>) {
    for x in vec {
        print!("{} ", x);
    }
    print!("\n");
}


impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        let mut left_max: Vec<i32> = vec![0; height.len()];
        let mut right_max: Vec<i32> = vec![0; height.len()];
        let mut trapped_units: Vec<i32> = vec![0; height.len()];
        for i in 1..height.len() - 1 {
            left_max[i] = cmp::max(left_max[i - 1], height[i - 1]);
        } 
        for i in (0..height.len() - 1).rev() {
            right_max[i] = cmp::max(right_max[i + 1], height[i + 1]);
        }
        for i in 1..height.len() - 1 {
            trapped_units[i] = cmp::max(
                0, 
                cmp::min(left_max[i], right_max[i]) - height[i]
            );
        }
        //vec_print(&height);
        //vec_print(&left_max);
        //vec_print(&right_max);
        //vec_print(&trapped_units);
        return trapped_units.iter().sum();
    }
}
