impl Solution {
    pub fn find_closest_elements(
        arr: Vec<i32>, k: i32, x: i32
    ) -> Vec<i32> {
        let mut closest_val_idx: usize = 0;
        let mut closest_val: i32 = i32::MAX;
        for i in 0..(&arr).len() {
            let diff: i32 = ((&arr)[i] - x).abs();
            if diff < closest_val {
                closest_val = diff;
                closest_val_idx = i;
            }
        }
        //println!("dbg: closest_val_idx={}", closest_val_idx);
        let mut out: Vec<i32> = vec![(&arr)[closest_val_idx]];
        let mut left: usize = closest_val_idx - 1;
        let mut right: usize = closest_val_idx + 1;
        while (
            (left as i32 >= 0 || right < (&arr).len())
            && (&out).len() < k as usize
         ) {
            let mut left_diff: i32 = i32::MAX;
            let mut right_diff: i32 = i32::MAX;
            if left as i32 >= 0 {
                left_diff = (x - (&arr)[left]).abs();
                //println!("dbg: left_diff={}", left_diff);
            }
            if right < (&arr).len() {
                right_diff = (x - (&arr)[right]).abs();
                //println!("dbg: right_diff={}", right_diff);
            }
            if left_diff < right_diff {
                //println!("dbg: push_left={}", left);
                out.push((&arr)[left]);
                left -= 1;
            } else if left_diff > right_diff {
                //println!("dbg: push_right={}", right);
                out.push((&arr)[right]);
                right += 1;
            } else {
                if (&arr)[left] < (&arr)[right] {
                    //println!("dbg: push_left={}", left);
                    out.push((&arr)[left]);
                    left -= 1; 
                } else {
                    //println!("dbg: push_right={}", right);
                    out.push((&arr)[right]);
                    right += 1;
                }
            }
        }
        out.sort();
        return out;
    }
}
