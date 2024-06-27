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


#[inline(always)]
fn tree2levels(
    dest: &mut Vec<Vec<i32>>, 
    node: &Option<Rc<RefCell<TreeNode>>>,
    level: i32
) {
    match node {
        None => {
            return;
        },
        Some(x) => {
            let left: &Option<Rc<RefCell<TreeNode>>> = {
                &x.borrow().left
            };
            let right: &Option<Rc<RefCell<TreeNode>>> = {
                &x.borrow().right
            };
            let val: i32 = x.borrow().val;
            while dest.len() as i32 - 1 < level {
                dest.push(Vec::new());
            }
            dest[level as usize].push(val);
            tree2levels(dest, left, level + 1);
            tree2levels(dest, right, level + 1);
            return;
        }
    }
}


impl Solution {
    #[inline(always)]
    pub fn is_even_odd_tree(
        root: Option<Rc<RefCell<TreeNode>>>
    ) -> bool {
        let mut levels: Vec<Vec<i32>> = Vec::new();
        tree2levels(&mut levels, &root, 0);
        for (i, vals) in levels.iter().enumerate() {
            if i % 2 == 0 {
                for (j, val) in vals.iter().enumerate() {
                    if val % 2 == 0 {
                        return false;
                    }
                    if j > 0 && *val <= vals[j - 1] {
                        return false;
                    }
                }
            } else if i % 2 != 0 {
                for (j, val) in vals.iter().enumerate() {
                    if val % 2 != 0 {
                        return false;
                    }
                    if j > 0 && *val >= vals[j - 1] {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
