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


unsafe fn to_raw_ptr(
    node: *const TreeNode, side: &str
) -> *const TreeNode {
    let mut wrapped_child: Option<&Rc<RefCell<TreeNode>>> = None;
    if side == "left" {
        wrapped_child = (*node).left.as_ref();
    } else {
        wrapped_child = (*node).right.as_ref();
    }
    let mut raw_ptr: *const TreeNode = std::ptr::null();
    match wrapped_child {
        Some(node) => {
            let refcell_ref: Ref<TreeNode> = node.borrow();
            raw_ptr = {
                &*refcell_ref as *const _ as *const TreeNode
            };
        },
        _ => {}
    }
    return raw_ptr;
}


unsafe fn solve(node: *const TreeNode, curr_depth: i32) -> i32 {
    if !node.is_null() {
        let left: *const TreeNode = to_raw_ptr(node, "left");
        let right: *const TreeNode = to_raw_ptr(node, "right");
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
                return unsafe { solve(raw_ptr, 0) };
            },
            _ => {
                return 0;
            }
        }
    }
}
