use std::io::{self, BufRead};

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

fn plusMinus(arr: &[i32]) {
    let mut pos_cnt: usize = 0;
    let mut neg_cnt: usize = 0;
    let mut zero_cnt: usize = 0;
    for x in arr.iter() {
        if x > &0 {
            pos_cnt += 1;
        } else if x < &0 {
            neg_cnt += 1;
        } else {
            zero_cnt += 1;
        }
    }
    println!("{}", pos_cnt as f32 / arr.len() as f32);
    println!("{}", neg_cnt as f32 / arr.len() as f32);
    println!("{}", zero_cnt as f32 / arr.len() as f32);
}

fn main() {
    let stdin = io::stdin();
    let mut stdin_iterator = stdin.lock().lines();

    let n = stdin_iterator.next().unwrap().unwrap().trim().parse::<i32>().unwrap();

    let arr: Vec<i32> = stdin_iterator.next().unwrap().unwrap()
        .trim_end()
        .split(' ')
        .map(|s| s.to_string().parse::<i32>().unwrap())
        .collect();

    plusMinus(&arr);
}

