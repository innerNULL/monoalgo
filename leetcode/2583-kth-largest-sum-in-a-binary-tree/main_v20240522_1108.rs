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
use std::fmt::Display;

fn tree_sum_by_levels(
    dest: &mut Vec<i64>, 
    node: &Option<Rc<RefCell<TreeNode>>>,
    level: usize
) {
    if node.is_none() {
        return;
    } 
    if level >= dest.len() {
        dest.push(0);
    }
    dest[level] = {
        (*node.as_ref().unwrap().borrow()).val as i64 + dest[level]
    };
    let left: &Option<Rc<RefCell<TreeNode>>> = {
        &(*node.as_ref().unwrap().borrow()).left
    };
    let right: &Option<Rc<RefCell<TreeNode>>> = {
        &(*node.as_ref().unwrap().borrow()).right
    };
    tree_sum_by_levels(dest, left, level + 1);
    tree_sum_by_levels(dest, right, level + 1);
    return;
}


fn dbg_vec_print<T: Display>(vec: &Vec<T>) {
    for x in vec {
        print!("{} ", x);
    }
    print!("\n");
}


impl Solution {
    pub fn kth_largest_level_sum(
        root: Option<Rc<RefCell<TreeNode>>>, 
        k: i32 // k > 0
    ) -> i64 {
        let mut level_sums: Vec<i64> = Vec::new();
        tree_sum_by_levels(&mut level_sums, &root, 0);
        //dbg_vec_print(&level_sums);
        if (&level_sums).len() < k as usize {
            return -1;
        } else {
            level_sums.sort_by(|a: &i64, b: &i64| { b.cmp(a) });
            return level_sums[k as usize - 1];
        }
    }
}
