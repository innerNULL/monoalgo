impl Solution {
    #[inline(always)]
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        if nums.len() <= 2 {
            return nums.len() as i32;
        }
        let mut writter: usize = 2;
        for i in 2..nums.len() {
            if nums[i] == nums[writter - 2] {
                continue;
            }
            nums[writter] = nums[i];
            writter += 1;
        }
        return writter as i32;
    }
}
