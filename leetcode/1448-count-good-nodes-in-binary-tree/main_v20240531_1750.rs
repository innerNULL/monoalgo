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


fn iterate(
    cnt: &mut i32, 
    upper_max: i32, 
    mut node: &Option<Rc<RefCell<TreeNode>>>
) {
    match node {
        None => {
            return;
        },
        Some(x) => {
            let val: i32 = x.as_ref().borrow().val;
            let left: &Option<Rc<RefCell<TreeNode>>> = 
                &x.as_ref().borrow().left;
            let right: &Option<Rc<RefCell<TreeNode>>> = 
                &x.as_ref().borrow().right;
            if val >= upper_max {
                *cnt += 1;
            }
            let next_upper_max: i32 = std::cmp::max(upper_max, val);
            iterate(cnt, next_upper_max, left);
            iterate(cnt, next_upper_max, right);
            return;
        }
    }
}


impl Solution {
    pub fn good_nodes(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut cnt: i32 = 0;
        iterate(&mut cnt, i32::MIN, &root);
        return cnt;
    }
}
