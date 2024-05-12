use std::io::{self, BufRead};

/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

fn miniMaxSum(arr: &mut Vec<i64>) {
    arr.sort();
    let min: i64 = arr[0..4].iter().sum::<i64>();
    let max: i64 = arr[1..5].iter().sum::<i64>();
    println!("{} {}", min, max);
}

fn main() {
    let stdin = io::stdin();
    let mut stdin_iterator = stdin.lock().lines();

    let mut arr: Vec<i64> = stdin_iterator.next().unwrap().unwrap()
        .trim_end()
        .split(' ')
        .map(|s| s.to_string().parse::<i64>().unwrap())
        .collect();

    miniMaxSum(&mut arr);
}

