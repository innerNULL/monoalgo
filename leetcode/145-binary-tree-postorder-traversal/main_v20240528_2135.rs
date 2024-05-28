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


fn solve(
    dest: &mut Vec<i32>, 
    node: &Option<Rc<RefCell<TreeNode>>>
) {
    match node {
        None => {
            return;
        },
        Some(x) => {
            let left: &Option<Rc<RefCell<TreeNode>>> = &x.borrow().left;
            let right: &Option<Rc<RefCell<TreeNode>>> = &x.borrow().right;
            solve(dest, left);
            solve(dest, right);
            dest.push(x.borrow().val);
            return;
        }
    }
}


impl Solution {
    pub fn postorder_traversal(
        root: Option<Rc<RefCell<TreeNode>>>
    ) -> Vec<i32> {
        let mut out: Vec<i32> = Vec::new();
        solve(&mut out, &root);
        return out;
    }
}
