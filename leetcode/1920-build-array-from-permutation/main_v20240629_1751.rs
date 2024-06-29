impl Solution {
    #[inline(always)]
    pub fn build_array(nums: Vec<i32>) -> Vec<i32> {
        return (&nums)
            .clone()
            .iter()
            .map(|x: &i32| {
                return (&nums)[*x as usize];
            })
            .collect::<Vec<i32>>();
    }
}
