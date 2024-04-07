impl Solution {
    pub fn merge(
        nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32
    ) {
        let mut reader1: usize = nums1.len() - nums2.len() - 1;
        let mut reader2: usize = nums2.len() - 1;
        let mut writter: usize = nums1.len() - 1;
        let mut break_flag: bool = false;
        while reader1 as i32 >= 0 && reader2 as i32 >= 0 {
            if nums1[reader1] >= nums2[reader2] {
                nums1[writter] = nums1[reader1];
                reader1 -= 1;
            } else {
                nums1[writter] = nums2[reader2];
                reader2 -= 1;
            }
            writter -= 1;
        }
        while reader2 as i32 >= 0 {
            nums1[writter] = nums2[reader2];
            reader2 -= 1;
            writter -= 1;
        }
    }
}
