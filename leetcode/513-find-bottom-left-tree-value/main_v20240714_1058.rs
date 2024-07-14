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
fn tree_group_by_layer(
    dest: &mut Vec<Vec<Rc<RefCell<TreeNode>>>>,
    root: Option<Rc<RefCell<TreeNode>>>,
    level: usize
) {
    match root {
        None => {
            return;
        },
        Some(node) => {
            if level >= dest.len() {
                dest.push(Vec::new());
            }
            let write_to: &mut Vec<Rc<RefCell<TreeNode>>> = {
                let idx: usize = dest.len() - 1;
                &mut dest[idx]
            };
            let left: Option<Rc<RefCell<TreeNode>>> = {
                node.borrow_mut().left.take()
            };
            let right: Option<Rc<RefCell<TreeNode>>> = {
                node.borrow_mut().right.take()
            };
            write_to.push(node);
            tree_group_by_layer(dest, left, level + 1);
            tree_group_by_layer(dest, right, level + 1);
            return;
        }
    }
}


impl Solution {
    #[inline(always)]
    pub fn find_bottom_left_value(
        mut root: Option<Rc<RefCell<TreeNode>>>
    ) -> i32 {
        let mut layers_nodes: Vec<Vec<Rc<RefCell<TreeNode>>>> = {
            Vec::new()
        };
        tree_group_by_layer(
            &mut layers_nodes,
            root, 
            0
        );
        return layers_nodes[layers_nodes.len() - 1][0].borrow().val;
    }
}
