impl Solution {
    #[inline(always)]
    pub fn num_water_bottles(
        mut num_bottles: i32, 
        num_exchange: i32
    ) -> i32 {
        let mut out: i32 = 0;
        while num_bottles >= num_exchange {
            let left_bottles: i32 = num_bottles % num_exchange;
            let drinked_bottles: i32 = num_bottles - left_bottles;
            let new_bottles: i32 = (num_bottles - left_bottles) / num_exchange;
            out += drinked_bottles;
            num_bottles = new_bottles + left_bottles;
        } 
        return out + num_bottles;
    }
}
