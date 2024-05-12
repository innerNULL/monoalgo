impl Solution {
    pub fn increasing_triplet(nums: Vec<i32>) -> bool {
        let mut smallest: i32 = i32::MAX;
        let mut medium: i32 = i32::MAX;
        for num in (&nums) {
            if num <= &smallest {
                smallest = *num;
            } else if num <= &medium {
                medium = *num;
            } else {
                return true;
            }
        }
        return false;
    }
}
