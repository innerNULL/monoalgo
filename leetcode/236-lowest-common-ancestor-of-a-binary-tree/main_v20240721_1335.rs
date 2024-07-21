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


use std::collections::HashMap;
use std::rc::Rc;
use std::cell::RefCell;


#[inline(always)]
fn tree_contains(
    root: &Option<Rc<RefCell<TreeNode>>>,
    node: &Option<Rc<RefCell<TreeNode>>>
) -> bool {
    match node {
        None => {
            return true;
        },
        Some(node_val) => {
            match root {
                None => {
                    return false;
                },
                Some(root_val) => {
                    let root_ptr: *const TreeNode = {
                        &*root_val.borrow() as *const TreeNode
                    };
                    let node_ptr: *const TreeNode = {
                        &*node_val.borrow() as *const TreeNode
                    };
                    if root_ptr == node_ptr {
                        return true;
                    } else {
                        let left: &Option<Rc<RefCell<TreeNode>>> = {
                            &root_val.borrow().left
                        };
                        let right: &Option<Rc<RefCell<TreeNode>>> = {
                            &root_val.borrow().right
                        };
                        return {
                            tree_contains(left, node) 
                            || tree_contains(right, node)
                        };
                    }
                }
            }
        }
    }
}


#[inline(always)]
fn solve(
    root: &Option<Rc<RefCell<TreeNode>>>, 
    p: &Option<Rc<RefCell<TreeNode>>>, 
    q: &Option<Rc<RefCell<TreeNode>>>
) -> Option<Rc<RefCell<TreeNode>>> {
    match root {
        None => {
            return None;
        },
        Some(root_node) => {
            let left: &Option<Rc<RefCell<TreeNode>>> = {
                &root_node.borrow().left
            };
            let right: &Option<Rc<RefCell<TreeNode>>> = {
                &root_node.borrow().right
            };
            let p_in_left: bool = tree_contains(left, p);
            let p_in_right: bool = tree_contains(right, p);
            let q_in_left: bool = tree_contains(left, q);
            let q_in_right: bool = tree_contains(right, q);
            if p_in_left && q_in_left {
                return solve(left, p, q);
            } else if p_in_right && q_in_right {
                return solve(right, p, q);
            } else {
                return Some(Rc::clone(&root_node));
            }
        }
    }
}


impl Solution {
    #[inline(always)]
    pub fn lowest_common_ancestor(
        root: Option<Rc<RefCell<TreeNode>>>, 
        p: Option<Rc<RefCell<TreeNode>>>, 
        q: Option<Rc<RefCell<TreeNode>>>
    ) -> Option<Rc<RefCell<TreeNode>>> {
        return solve(&root, &p, &q);   
    }
}
