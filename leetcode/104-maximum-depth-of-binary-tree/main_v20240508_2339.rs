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
use std::cell::Ref;


unsafe fn solve(node: *const TreeNode, curr_depth: i32) -> i32 {
    if !node.is_null() {
        let left: *const TreeNode = match (*node).left.as_ref() {
            Some(node) => {
                let refcell_ref: Ref<TreeNode> = node.borrow();
                let raw_ptr: *const TreeNode = {
                    &*refcell_ref as *const _ as *const TreeNode
                };
                raw_ptr
            },
            None => {
                std::ptr::null()
            }
        };
        let right: *const TreeNode = match (*node).right.as_ref() {
            Some(node) => {
                let refcell_ref: Ref<TreeNode> = node.borrow();
                let raw_ptr: *const TreeNode = {
                    &*refcell_ref as *const _ as *const TreeNode
                };
                raw_ptr
            },
            None => {
                std::ptr::null()
            }
        };
        return std::cmp::max(
            solve(left, curr_depth + 1), 
            solve(right, curr_depth + 1)
        );
    }
    return curr_depth;
}


impl Solution {
    pub fn max_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        match root {
            Some(node) => {
                let refcell_ref: Ref<TreeNode> = node.borrow();
                let raw_ptr: *const TreeNode = {
                    &*refcell_ref as *const _ as *const TreeNode
                };
                unsafe { solve(raw_ptr, 0) }
            },
            _ => {
                0
            }
        }
    }
}
