impl Solution {
    pub fn intersection(
        mut nums1: Vec<i32>, mut nums2: Vec<i32>
    ) -> Vec<i32> {
        let mut out: Vec<i32> = Vec::new();
        nums1.sort();
        nums2.sort();
        let mut reader1: usize = 0;
        let mut reader2: usize = 0;
        while reader1 < nums1.len() && reader2 < nums2.len() {
            let val1: i32 = nums1[reader1];
            let val2: i32 = nums2[reader2];
            if val1 < val2 {
                reader1 += 1; 
            } else if val1 > val2 {
                reader2 += 1; 
            } else {
                out.push(val1);
                reader1 += 1;
                reader2 += 1;
            }
        }
        out.dedup();
        return out;
    }
}
