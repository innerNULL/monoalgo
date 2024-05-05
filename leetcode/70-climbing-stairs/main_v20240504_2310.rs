use std::collections::HashMap;


fn solve(n: i32, cache: &mut HashMap<i32, i32>) -> i32 {
    if n == 0 {
        0
    } else if n == 1 {
        1
    } else if n == 2 {
        2
    } else if cache.contains_key(&n) {
        cache.get(&n).unwrap().clone()
    } else {
        let result: i32 = solve(n - 1, cache) + solve(n - 2, cache);
        cache.insert(n, result);
        result
    }
}


impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        let mut cache: HashMap<i32, i32> = HashMap::new();
        return solve(n, &mut cache);
    }
}
