fn dbg_vec_print(vec: &Vec<i32>) {
    for x in vec {
        print!("{} ", x);
    }
    print!("\n");
}


fn dbg_vecs_print(vecs: &Vec<Vec<i32>>) {
    for vec in vecs {
        dbg_vec_print(vec);
    }
}


impl Solution {
    pub fn insert(
        intervals: Vec<Vec<i32>>, new_interval: Vec<i32>
    ) -> Vec<Vec<i32>> {
        if (&intervals).len() == 0 {
            return vec![new_interval];
        }
        let mut out: Vec<Vec<i32>> = Vec::new();
        let mut start_range_idx: i32 = -1;
        let mut end_range_idx: i32 = -1;
        for i in 0..(&intervals).len() {
            //println!("dbg: i={}", i);
            let range: &Vec<i32> = &(&intervals)[i];
            if (
                range[0] >= (&new_interval)[0] 
                && range[1] <= (&new_interval)[1]
            ) || (
                range[0] <= (&new_interval)[1] 
                && range[1] >= (&new_interval)[1]
            ) || (
                range[0] <= (&new_interval)[0] 
                && range[1] >= (&new_interval)[0]
            ) {
                if start_range_idx == -1 {
                    start_range_idx = i as i32;
                    //println!("dbg: start_range_idx={}", start_range_idx);
                }
                end_range_idx = i as i32;
                //println!("dbg: end_range_idx={}", end_range_idx);
            }
        }
        /*
        println!("dbg: new_interval:");
        dbg_vec_print(&new_interval);
        println!("dbg: intervals");
        dbg_vecs_print(&intervals);
        println!("dbg: start_range_idx={}", start_range_idx);
        println!("dbg: end_range_idx={}", end_range_idx);
        */

        if start_range_idx == -1 && end_range_idx == -1 {
            out = intervals.clone();
            if (&new_interval)[0] > (&intervals)[&intervals.len() - 1][1] {
                out.push(new_interval.clone());
            } else if (&new_interval)[1] < (&intervals)[0][0] {
                out.insert(0, new_interval.clone());
            } else {
                for i in 1..(&intervals).len() {
                    if (&new_interval)[0] > (&intervals)[i - 1][1] 
                        && (&new_interval)[1] < (&intervals)[i][0] 
                    {
                        out.insert(i, new_interval.clone());
                        break;
                    }
                }
            }
            return out;
        }

        let mut left: i32 = 0;
        let mut right: i32 = 0;
        for i in 0..(&intervals).len() {
            if (i as i32) < start_range_idx 
                || (i as i32) > end_range_idx 
            {   
                //println!("dbg: i={}", i);
                out.push((&intervals)[i].clone());
            }
            if i as i32 == start_range_idx {
                left = std::cmp::min(
                    (&intervals)[i][0], 
                    (&new_interval)[0]
                );
            } 
            if i as i32 == end_range_idx {
                right = std::cmp::max(
                    (&intervals)[i][1],
                    (&new_interval)[1]
                );
                out.push(vec![left, right]);
            }
        }
        return out;
    }
}
