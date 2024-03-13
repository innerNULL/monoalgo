fn match_str(
    haystack: &String, needle: &String, start_idx: usize
) -> bool {
    let str_len = haystack.len();
    if str_len - needle.len() < start_idx {
        return false;
    }
    for i in 0..needle.len() as usize {
        if haystack.chars().nth(start_idx + i) != needle.chars().nth(i) {
            return false;
        }
    }
    return true;
}


impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        for i in 0..haystack.len() as usize {
            if match_str(&haystack, &needle, i) {
                return i as i32;
            }
        }
        return -1;
    }
}
