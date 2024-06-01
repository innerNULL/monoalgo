use std::fmt::Display;


#[inline(always)]
fn vec_print<T>(vec: &Vec<T>) 
where 
    T: Display
{
    for x in vec {
        print!("{} ", x);
    }
    print!("\n");
}


#[inline(always)]
fn backtrack(
    dest: &mut Vec<Vec<i32>>, 
    buffer: &mut Vec<i32>, 
    target: i32, 
    k: i32, 
    num: i32
) {
    if k == 0 {
        let sum: i32 = buffer
            .into_iter()
            .map(|x: &mut i32| { *x })
            .sum::<i32>();
        if sum == target {
            dest.push(buffer.clone());
        }
        return;
    }
    if num > 9 {
        return;
    }
    
    buffer.push(num);
    backtrack(dest, buffer, target, k - 1, num + 1);
    buffer.pop();
    backtrack(dest, buffer, target, k, num + 1);
}


impl Solution {
    #[inline(always)]
    pub fn combination_sum3(
        k: i32, 
        n: i32
    ) -> Vec<Vec<i32>> {
        let mut out: Vec<Vec<i32>> = Vec::new();
        let mut buffer: Vec<i32> = Vec::new();
        backtrack(&mut out, &mut buffer, n, k, 1);
        return out;
    }
}
