impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let mut all_product: i32 = 1;
        let mut all_non_zero_product: i32 = 1;
        let mut zero_cnt: i32 = 0;
        for num in &nums {
            all_product *= num;
            if *num != 0 {
                all_non_zero_product *= num;
            } else {
                zero_cnt += 1;
            }
        }
        let mut out: Vec<i32> = Vec::new();
        for num in &nums {
            match num {
                0 => {
                    if zero_cnt == 1 {
                        out.push(all_non_zero_product);
                    } else {
                        out.push(0);
                    }
                },
                _ => {
                    out.push(all_product / num);
                }
            }
        }
        return out;
    }
}
