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
fn tree2vec(
    dest: &mut Vec<Option<Rc<RefCell<TreeNode>>>>,
    node: Option<Rc<RefCell<TreeNode>>>
) {
    match node {
        None => {
            return;
        },
        Some(ref x) => {
            let left: Option<Rc<RefCell<TreeNode>>> = x
                .borrow_mut()
                .left
                .take();
            let right: Option<Rc<RefCell<TreeNode>>> = x
                .borrow_mut()
                .right
                .take();
            dest.push(node);
            tree2vec(dest, left);
            tree2vec(dest, right);
            return;
        }
    }
}


#[inline(always)]
fn clone_slicing(
    nodes: &mut Vec<Option<Rc<RefCell<TreeNode>>>>, 
    left: usize, 
    right: usize
) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
    let mut out: Vec<Option<Rc<RefCell<TreeNode>>>> = Vec::new();
    if left < 0 || right >= nodes.len() || left > right {
        return out;
    }
    for i in left..=right {
        out.push(nodes[i].take());
    }
    return out;
}


#[inline(always)]
fn build_bst(
    nodes: &mut Vec<Option<Rc<RefCell<TreeNode>>>>
) -> Option<Rc<RefCell<TreeNode>>> {
    let nodes_cnt: usize = nodes.len();
    let mut new_root: Option<Rc<RefCell<TreeNode>>> = None;
    if nodes_cnt == 1 { 
        new_root = nodes[0].take();
    } else if nodes_cnt == 2 {
        new_root = nodes[0].take();
        let mut right: Option<Rc<RefCell<TreeNode>>> = nodes[1].take();
        new_root.as_mut().unwrap().borrow_mut().right = right.take();
    } else {
        let mid_idx: usize = nodes_cnt / 2;
        new_root = nodes[mid_idx].take();
        let mut left_part: Vec<Option<Rc<RefCell<TreeNode>>>> = {
            clone_slicing(nodes, 0, mid_idx - 1)
        };
        let mut right_part: Vec<Option<Rc<RefCell<TreeNode>>>> = {
            clone_slicing(nodes, mid_idx + 1, nodes_cnt - 1)
        };
        new_root.as_mut().unwrap().borrow_mut().left = {
            build_bst(&mut left_part)
        };
        new_root.as_mut().unwrap().borrow_mut().right = {
            build_bst(&mut right_part)
        };
    }
    return new_root;
}


impl Solution {
    #[inline(always)]
    pub fn balance_bst(
        root: Option<Rc<RefCell<TreeNode>>>
    ) -> Option<Rc<RefCell<TreeNode>>> {
        let mut nodes: Vec<Option<Rc<RefCell<TreeNode>>>> = Vec::new();
        tree2vec(&mut nodes, root);
        nodes.sort_by(
            |
                a: &Option<Rc<RefCell<TreeNode>>>, 
                b: &Option<Rc<RefCell<TreeNode>>>
            | {
                let val_a: i32 = a
                    .as_ref()
                    .unwrap()
                    .borrow()
                    .val;
                let val_b: i32 = b
                    .as_ref()
                    .unwrap()
                    .borrow()
                    .val;
                return val_a.cmp(&val_b);
            }
        );
        return build_bst(&mut nodes);
    }
}
