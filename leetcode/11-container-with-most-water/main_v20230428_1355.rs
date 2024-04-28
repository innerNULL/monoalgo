impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut left_idx: usize = 0;
        let mut right_idx: usize = height.len() - 1;
        let mut max_area: i32 = 0;
        while left_idx < right_idx {
            let left_height: i32 = (&height)[left_idx];
            let right_height: i32 = (&height)[right_idx];
            let width: i32 = (right_idx - left_idx) as i32;
            max_area = std::cmp::max(
                max_area, 
                std::cmp::min(left_height, right_height) * width
            );
            if left_height < right_height {
                left_idx += 1;
            } else {
                right_idx -= 1;
            }
        }
        return max_area;
    }
}
