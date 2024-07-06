impl Solution {
    #[inline(always)]
    pub fn single_number(mut nums: Vec<i32>) -> i32 {
        if nums.len() < 2 {
            return nums[0];
        }
        nums.sort();
        let mut out: i32 = -1;
        nums
            .iter()
            .enumerate()
            .for_each(
                |x: (usize, &i32)| {
                    let i: usize = x.0;
                    let val: i32 = x.1.clone();
                    if i == 0 {
                        if val != nums[i + 1] {
                            out = val;
                        }
                    } else if i == nums.len() - 1 {
                        if val != nums[i - 1] {
                            out = val;
                        }
                    } else {
                        if val != nums[i - 1] && val != nums[i + 1] {
                            out = val;
                        } 
                    }
                    return;
                }
            );
        return out;
    }
}
