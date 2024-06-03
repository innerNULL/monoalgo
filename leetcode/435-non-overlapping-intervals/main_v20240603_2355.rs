use std::cmp::Ordering;
use std::fmt::Display;


fn vec_print<T>(vec: &Vec<T>) 
where
    T: Display
{
    for x in vec {
        print!("{} ", x);
    }
    print!("\n");
}


fn mat_print<T>(mat: &Vec<Vec<T>>) 
where
    T: Display
{
    for vec in mat {
        vec_print(vec);
    }
}


impl Solution {
    #[inline(always)]
    pub fn erase_overlap_intervals(mut intervals: Vec<Vec<i32>>) -> i32 {
        intervals.sort_by(
            |a: &Vec<i32>, b: &Vec<i32>| {
                if a[1] < b[1] {
                    return Ordering::Less;
                } else if a[1] > b[1] {
                    return Ordering::Greater;
                } else {
                    return a[0].cmp(&b[0]);
                }
            }
        );
        //mat_print(&intervals);
        let mut cnt: i32 = 0;
        let mut last_interval: &Vec<i32> = &intervals[0];
        for i in 1..intervals.len() {
            let curr_interval: &Vec<i32> = &intervals[i];
            if curr_interval[0] < last_interval[1] {
                cnt += 1;
            } else {
                last_interval = curr_interval
            }
        }
        return cnt;
    }
}
