impl Solution {
    pub fn largest_altitude(gain: Vec<i32>) -> i32 {
        let mut curr_altitude: i32 = 0;
        let mut max_altitude: i32 = 0;
        for i in 0..(&gain).len() {
            curr_altitude += (&gain)[i];
            max_altitude = std::cmp::max(max_altitude, curr_altitude);
        }
        return max_altitude;
    }
}
