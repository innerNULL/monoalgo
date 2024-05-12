unsafe fn solve(n: i32, cache: *mut Vec<i32>) -> i32 {
    if n == 0 {
        return 0;
    } else if n == 1 || n == 2 {
        return 1;
    } else if (*cache)[n as usize] != -1 {
        return (*cache)[n as usize];
    } else {
        let result: i32 = 
            solve(n - 1, cache) + solve(n - 2, cache) + solve(n - 3, cache);
        (*cache)[n as usize] = result;
        return result;
    }
}


impl Solution {
    pub fn tribonacci(n: i32) -> i32 {
        let mut cache: Vec<i32> = vec![-1; (n + 1) as usize];
        return unsafe { solve(n, &mut cache as *mut Vec<i32>) };
    }
}
