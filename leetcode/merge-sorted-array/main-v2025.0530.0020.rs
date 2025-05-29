impl Solution {
    pub fn merge(
        nums1: &mut Vec<i32>, 
        m: i32, 
        nums2: &mut Vec<i32>, 
        n: i32
    ) {
        let mut reader1: usize = (m - 1) as usize;
        let mut reader2: usize = (n - 1) as usize;
        let mut writter: usize = reader1 + reader2 + 1;
        while (reader1 as i32 >= 0 && reader2 as i32 >= 0) {
            let val1: i32 = nums1[reader1];
            let val2: i32 = nums2[reader2];
            if val1 >= val2 {
                nums1[writter] = val1;
                reader1 -= 1;
            } else {
                nums1[writter] = val2;
                reader2 -= 1;
            }
            writter -= 1;
        }
        while reader2 as i32 >= 0 {
            nums1[writter] = nums2[reader2];
            reader2 -= 1;
            writter -= 1;
        }
        return;    
    }
}
