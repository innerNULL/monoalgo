impl Solution {
    #[inline(always)]
    pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
        let mut out: Vec<String> = Vec::new();
        for i in 0..nums.len() {
            if i == 0 {
                out.push(nums[i].to_string());
            } else {
                if nums[i] as i64 - nums[i - 1] as i64 > 1 {
                    let last_entry: &mut String = {
                        let len: usize = out.len();
                        &mut out[len - 1]
                    };
                    let curr_entry: String = nums[i - 1].to_string();
                    if curr_entry != *last_entry {
                        *last_entry = last_entry.clone() + "->" + &curr_entry;
                    }
                    out.push(nums[i].to_string());
                } else if i == nums.len() - 1 {
                    let last_entry: &mut String = {
                        let len: usize = out.len();
                        &mut out[len - 1]
                    };
                    let curr_entry: String = nums[i].to_string();
                    *last_entry = last_entry.clone() + "->" + &curr_entry;
                }
            }
        }
        return out;   
    }
}
