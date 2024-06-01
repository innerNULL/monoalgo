// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }


use std::rc::Rc;
use std::cell::RefCell;


#[inline]
fn level_sums_init(
    dest: &mut Vec<i32>, 
    level: usize,
    node: &Option<Rc<RefCell<TreeNode>>>
) {
    match node {
        None => {
            return;
        },
        Some(x) => {
            let val: i32 = x.borrow().val;
            let left: &Option<Rc<RefCell<TreeNode>>> = {
                &x.borrow().left
            };
            let right: &Option<Rc<RefCell<TreeNode>>> = {
                &x.borrow().right
            };
            let level_idx: usize = level - 1;
            while dest.len() < level {
                dest.push(0);
            }
            dest[level_idx] += val;
            level_sums_init(dest, level + 1, left);
            level_sums_init(dest, level + 1, right);
            return;
        }
    }
}


impl Solution {
    #[inline]
    pub fn max_level_sum(
        root: Option<Rc<RefCell<TreeNode>>>
    ) -> i32 {
        let mut level_sums: Vec<i32> = Vec::new();
        level_sums_init(&mut level_sums, 1, &root);
        let mut max_sum_level: usize = 1;
        let mut max_sum: i32 = level_sums[0];
        for (level_idx, sum) in level_sums.iter().enumerate() {
            if *sum > max_sum {
                max_sum_level = level_idx + 1;
                max_sum = *sum;
            }
        }
        return max_sum_level as i32;
    }
}
