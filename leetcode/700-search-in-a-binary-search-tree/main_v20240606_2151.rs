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
fn solve(
    node: &mut Option<Rc<RefCell<TreeNode>>>, 
    target: i32
) -> Option<Rc<RefCell<TreeNode>>> {
    match node {
        None => {
            return None;
        },
        Some(ref x) => {
            let val: i32 = x.borrow().val;
            if val == target {
                return node.take();
            } else if val > target {
                let left: &mut Option<Rc<RefCell<TreeNode>>> = {
                    &mut x.borrow_mut().left
                };
                return solve(left, target);
            } else {
                let right: &mut Option<Rc<RefCell<TreeNode>>> = {
                    &mut x.borrow_mut().right
                };
                return solve(right, target);
            }
        }
    }
}


impl Solution {
    #[inline(always)]
    pub fn search_bst(
        mut root: Option<Rc<RefCell<TreeNode>>>, 
        val: i32
    ) -> Option<Rc<RefCell<TreeNode>>> {
        return solve(&mut root, val);
    }
}
