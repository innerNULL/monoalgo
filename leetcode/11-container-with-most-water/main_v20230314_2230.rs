use std::cmp;


impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut left_idx: usize = 0;
        let mut right_idx: usize = height.len() - 1;
        let mut max_area: i32 = 0;
        while left_idx < right_idx {
            let min_height: i32 = cmp::min(
                height[left_idx], height[right_idx]
            );
            let width: i32 = (right_idx - left_idx) as i32;
            let area: i32 = width * min_height;
            max_area = cmp::max(max_area, area);
            if height[left_idx] < height[right_idx] {
                left_idx += 1;
            } else if height[left_idx] > height[right_idx] {
                right_idx -= 1;
            } else {
                left_idx += 1;
                right_idx -= 1;
            }
        }
        return max_area;
    }
}
