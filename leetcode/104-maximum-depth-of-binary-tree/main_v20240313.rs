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


use std::cmp;


fn get_depth(
    node: &Option<Rc<RefCell<TreeNode>>>, curr_depth: i32
) -> i32 {
    if node.is_none() { return curr_depth; }
    return cmp::max(
        get_depth(
            &(node.as_ref().unwrap().borrow().left), curr_depth + 1
        ), 
        get_depth(
            &(node.as_ref().unwrap().borrow().right), curr_depth + 1
        )
    );
}


use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn max_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        return get_depth(&root, 0);
    }
}
