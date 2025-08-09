fn merge_sorted(
    nums1: &Vec<i32>,
    nums2: &Vec<i32>
) -> Vec<i32> {
    let mut out: Vec<i32> = vec![0; nums1.len() + nums2.len()];
    let mut idx1: usize = 0;
    let mut idx2: usize = 0;
    let mut writter: usize = 0;
    while idx1 < nums1.len() || idx2 < nums2.len() {
        let val1: Option<i32> = match (idx1 >= nums1.len()) {
            true => None,
            _ => Some((&nums1)[idx1])
        };
        let val2: Option<i32> = match (idx2 >= nums2.len()) {
            true => None,
            _ => Some((&nums2)[idx2])
        };
        if val1.is_none() {
            out[writter] = val2.unwrap();
            idx2 += 1;
        } else if val2.is_none() {
            out[writter] = val1.unwrap();
            idx1 += 1;
        } else {
            match val1 > val2 {
                true => {
                    out[writter] = val2.unwrap();
                    idx2 += 1;
                },
                _ => {
                    out[writter] = val1.unwrap();
                    idx1 += 1;
                }
            }
        }
        writter += 1;
    }
    return out;
}


impl Solution {
    pub fn find_median_sorted_arrays(
        nums1: Vec<i32>, 
        nums2: Vec<i32>
    ) -> f64 {
        let len_1: usize = (&nums1).len();
        let len_2: usize = (&nums2).len();
        let total_cnt: usize = len_1 + len_2;
        let mut cand_idx_1: Option<usize> = None;
        let mut cand_idx_2: Option<usize> = None;
        match (total_cnt % 2) {
            0 => {
                cand_idx_2 = Some(total_cnt / 2);
                cand_idx_1 = Some(cand_idx_2.unwrap() - 1);
            },
            _ => {
                cand_idx_1 = Some(total_cnt / 2);
                cand_idx_2 = cand_idx_1.clone();
            }
        }
        let sorted_all: Vec<i32> = merge_sorted(&nums1, &nums2);
        //println!("Sorted & merged vector: {:?}", sorted_all);
        //println!("Median indexs: {}, {}", cand_idx_1.unwrap(), cand_idx_2.unwrap());
        return {
            (
                (sorted_all[cand_idx_1.unwrap()] as f64)
                + (sorted_all[cand_idx_2.unwrap()] as f64)
            ) / 2.0 
        };
    }
}
