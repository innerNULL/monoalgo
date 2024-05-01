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


fn vals_collect(
    dest: &mut Vec<i32>, 
    node: &Option<Rc<RefCell<TreeNode>>>
) {
    match node {
        Some(ref inner) => {
            let val: i32 = inner.borrow().val;
            dest.push(val);
            vals_collect(dest, &(inner.borrow().left));
            vals_collect(dest, &(inner.borrow().right));
            return;
        },
        None => {
            return;
        },
    }
}


fn dbg_vec_print(vec: &Vec<i32>) {
    for x in vec {
        print!("{} ", x);
    }
    print!("\n");
}


impl Solution {
    pub fn get_minimum_difference(
        root: Option<Rc<RefCell<TreeNode>>>
    ) -> i32 {
        let mut vals: Vec<i32> = Vec::new();
        vals_collect(&mut vals, &root);
        vals.sort();
        //dbg_vec_print(&vals);
        let mut out: i32 = i32::MAX;
        for i in 1..vals.len() {
            out = std::cmp::min(
                out,
                (&vals)[i] - (&vals)[i - 1]
            );
        }
        return out;
    }
}
