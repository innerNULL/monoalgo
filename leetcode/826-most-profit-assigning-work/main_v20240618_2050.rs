use std::cmp::Ordering;


fn vec_tuple_print(vec: &Vec<(i32, i32)>) {
    for x in vec {
        println!("{} {}", x.0, x.1);
    }
}


impl Solution {
    #[inline(always)]
    pub fn max_profit_assignment(
        difficulty: Vec<i32>, 
        profit: Vec<i32>, 
        mut worker: Vec<i32>
    ) -> i32 {
        let mut diff_and_profit: Vec<(i32, i32)> = {
            let mut out: Vec<(i32, i32)> = Vec::new();
            for i in 0..difficulty.len() {
                out.push(
                    ((&difficulty)[i], (&profit)[i])
                );
            }
            out
        };
        diff_and_profit.sort_by(
            |a: &(i32, i32), b: &(i32, i32)| {
                if a.1 < b.1 {
                    return Ordering::Greater;
                } else if a.1 > b.1 {
                    return Ordering::Less;
                } else {
                    if a.0 < b.0 {
                        return Ordering::Greater;
                    } else if a.0 > b.0 {
                        return Ordering::Less;
                    } else {
                        return Ordering::Equal;
                    }
                }
            }
        );
        worker.sort_by(
            |a: &i32, b: &i32| {
                if a < b {
                    return Ordering::Greater;
                } else if a > b {
                    return Ordering::Less;
                } else {
                    return Ordering::Equal;
                }
            }
        );
        //vec_tuple_print(&diff_and_profit);
        let mut profit: i32 = 0;
        let mut task_id: usize = 0;
        for worker_id in 0..worker.len() {
            let quota: i32 = (&worker)[worker_id];
            while (
                task_id < diff_and_profit.len() 
                && (&diff_and_profit)[task_id].0 > quota
            ) {
                task_id += 1
            }
            if task_id >= diff_and_profit.len() {
                break;
            } else {
                profit += (&diff_and_profit)[task_id].1;
            }
        }
        return profit;
    }
}
