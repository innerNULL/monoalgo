impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut writter: usize = 0;
        let mut reader: usize = 0; 
        while reader < nums.len() {
            if nums[reader] != val {
                nums[writter] = nums[reader];
                writter += 1;
            }
            reader += 1;
        }
        return writter as i32;
    }
}
