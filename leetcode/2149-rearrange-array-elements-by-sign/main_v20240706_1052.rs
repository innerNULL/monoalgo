impl Solution {
    #[inline(always)]
    pub fn rearrange_array(nums: Vec<i32>) -> Vec<i32> {
        let mut out: Vec<i32> = Vec::new();
        let pos: Vec<i32> = nums
            .iter()
            .map(|x: &i32| { return x.clone(); })
            .filter(|x: &i32| { return *x > 0; })
            .collect::<Vec<i32>>();
        let neg: Vec<i32> = nums
            .iter()
            .map(|x: &i32| { return x.clone(); })
            .filter(|x: &i32| { return *x < 0; })
            .collect::<Vec<i32>>();
        let max_len: i32 = std::cmp::max(
            pos.len() as i32, neg.len() as i32
        );
        (0..max_len)
            .for_each(
                |i: i32| {
                    if i < (pos.len() as i32) {
                        out.push(pos[i as usize]);
                    }
                    if i < (neg.len() as i32) {
                        out.push(neg[i as usize]);
                    }
                }
            );
        return out;
    }
}
