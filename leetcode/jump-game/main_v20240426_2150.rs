unsafe fn check(
    idx: usize, nums: *mut Vec<i32>, cache: *mut Vec<i8>
) -> bool {
    if idx == (*nums).len() - 1 { 
        return true; 
    }
    if (*nums)[idx] == 0 { 
        return false; 
    }
    if (*cache)[idx] != -1 { 
        return (idx == 1); 
    }
    for i in (idx + 1)..(idx + (*nums)[idx] as usize + 1) {
        if i < (*nums).len() && check(i, nums, cache) {
            return true;
        }
    }
    (*cache)[idx] = 0;
    return false;
}


impl Solution {
    pub fn can_jump(mut nums: Vec<i32>) -> bool {
        let mut cache: Vec<i8> = vec![-1; nums.len()];
        unsafe {
            return check(
                0, 
                &mut nums as *mut Vec<i32>, 
                &mut cache as *mut Vec<i8>
            );
        }
    }
}
