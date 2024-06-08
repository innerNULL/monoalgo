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
        vec_print::<T>(vec);
    }
}


impl Solution {
    #[inline(always)]
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        if nums.iter().sum::<i32>() == nums.len() as i32 {
            return nums.len() as i32 - 1;
        } 
        if nums.iter().sum::<i32>() == 0 {
            return 0;
        }
        let mut ones_range: Vec<Vec<i32>> = Vec::new();
        for i in 0..nums.len() {
            if nums[i] == 1 {
                if i == 0 || nums[i - 1] == 0 {
                    ones_range.push(vec![i as i32, -1]);
                }
            }
        }
        for range in &mut ones_range {
            let left: i32 = (*range)[0];
            let mut right: i32 = left;
            while (
                (right as usize) < nums.len() 
                && nums[right as usize] == 1
            ) {
                right += 1;
            }
            (*range)[1] = right - 1;
        }
        //mat_print(&ones_range);
        let mut merged_lens: Vec<i32> = vec![
            &ones_range[0][1] - &ones_range[0][0] + 1
        ];
        for i in 1..ones_range.len() {
            let curr_range: &Vec<i32> = &ones_range[i];
            let last_range: &Vec<i32> = &ones_range[i - 1];
            if curr_range[0] - last_range[1] == 2 {
                merged_lens.push(curr_range[1] - last_range[0]);
            } else {
                merged_lens.push(curr_range[1] - curr_range[0] + 1);
            }
        }
        //vec_print(&merged_lens);
        return merged_lens.iter().max().unwrap().clone();
    }
}
