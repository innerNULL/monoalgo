use std::collections::HashSet;


fn vec2set(dest: &mut HashSet<i32>, inputs: &Vec<i32>) {
    for x in inputs {
        dest.insert(x.clone());
    }
    return;
}


fn diff_a_on_b(a: Vec<i32>, b: HashSet<i32>) -> Vec<i32> {
    let mut out: HashSet<i32> = HashSet::new();
    for x in a {
        if !b.contains(&x) {
            out.insert(x);
        }
    }
    return out.drain().collect::<Vec<i32>>();;
}


impl Solution {
    pub fn find_difference(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<Vec<i32>> {
        let mut set1: HashSet<i32> = HashSet::new();
        let mut set2: HashSet<i32> = HashSet::new();
        vec2set(&mut set1, &nums1);
        vec2set(&mut set2, &nums2);
        return vec![
            diff_a_on_b(nums1, set2),
            diff_a_on_b(nums2, set1)
        ];
    }
}
