fn vec_reverse(
    vec: &mut Vec<i32>, mut left_idx: usize, mut right_idx: usize
) {
    while left_idx < right_idx {
        let tmp: i32 = vec[left_idx];
        vec[left_idx] = vec[right_idx];
        vec[right_idx] = tmp;
        left_idx += 1;
        right_idx -= 1;
    }
}


impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let real_k: usize = (k % (nums.len() as i32)) as usize;
        if real_k > 0 {
            vec_reverse(nums, 0, nums.len() - 1);
            vec_reverse(nums, 0, real_k - 1);
            vec_reverse(nums, real_k, nums.len() - 1);
        }
    }
}
