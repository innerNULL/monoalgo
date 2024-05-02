impl Solution {
    pub fn find_peak_element(nums: Vec<i32>) -> i32 {
        if (&nums).len() <= 1 {
            return 0;
        }
        let mut marks: Vec<i8> = vec![0; nums.len()];
        for i in 1..(&nums).len() {
            if (&nums)[i] > (&nums)[i - 1] {
                (&mut marks)[i] = 1;
            }
        } 
        for i in (0..=(&nums).len() - 2).rev() {
            if (&nums)[i] <= (&nums)[i + 1] {
                (&mut marks)[i] = 0;
            }
        }
        for i in 0..(&marks).len() {
            if (&marks)[i] == 1 {
                return i as i32;
            }
        }
        return 0;
    }
}
