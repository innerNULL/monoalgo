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


fn solve(nums: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
    match (&nums).len() {
        0 => {
            return None;
        },
        1 => {
            return Some(
                Rc::new(RefCell::new(
                    TreeNode::new((&nums)[0])
                ))
            );
        },
        2 => {
            let mut root: TreeNode = TreeNode::new((&nums)[1]);
            let child: TreeNode = TreeNode::new((&nums)[0]);
            root.left = Some(Rc::new(RefCell::new(child)));
            return Some(Rc::new(RefCell::new(root)));
        },
        _ => {
            let mid: usize = (&nums).len() / 2;
            let mut root: TreeNode = TreeNode::new((&nums)[mid]);
            root.left = solve((&nums)[0..mid].to_vec());
            root.right = solve((&nums)[mid + 1..(&nums).len()].to_vec());
            return Some(Rc::new(RefCell::new(root)));
        }
    };
}


impl Solution {
    pub fn sorted_array_to_bst(
        nums: Vec<i32>
    ) -> Option<Rc<RefCell<TreeNode>>> {
        return solve(nums);
    }
}
