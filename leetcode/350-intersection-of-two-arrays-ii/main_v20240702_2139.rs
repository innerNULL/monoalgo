use std::collections::HashMap;
use std::collections::HashSet;


#[inline(always)]
fn vec2hashmap(input: &Vec<i32>) -> HashMap<i32, i32> {
    let mut out: HashMap<i32, i32> = HashMap::new();
    input
        .iter()
        .for_each(
            |x: &i32| {
                let entry: Option<&mut i32> = out.get_mut(x);
                match entry {
                    None => {
                        out.insert(x.clone(), 1);
                    },
                    Some(x) => {
                        *x += 1;
                    }
                }
            }
        );
    return out;
}


impl Solution {
    #[inline(always)]
    pub fn intersect(
        mut nums1: Vec<i32>, 
        mut nums2: Vec<i32>
    ) -> Vec<i32> {
        let mut out: Vec<i32> = Vec::new();
        let mut recorder1: HashMap<i32, i32> = vec2hashmap(&nums1);
        let mut recorder2: HashMap<i32, i32> = vec2hashmap(&nums2);
        nums1
            .iter()
            .chain(
                nums2.iter()
            )
            .map(|x: &i32| { return x.clone(); })
            .collect::<HashSet<i32>>()
            .iter()
            .for_each(
                |x: &i32| {
                    let cnt1: Option<&i32> = recorder1.get(x);
                    let cnt2: Option<&i32> = recorder2.get(x);
                    if (!cnt1.is_none()) && (!cnt2.is_none()) {
                        let cnt: i32 = std::cmp::min(
                            cnt1.unwrap().clone(), cnt2.unwrap().clone()
                        );
                        for i in 0..cnt as usize {
                            out.push(x.clone());
                        }
                    }
                    return;
                }
            );
        return out;
    }
}
